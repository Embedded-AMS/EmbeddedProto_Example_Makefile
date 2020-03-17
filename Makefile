
# Define the name of the project
PROJECT = example

# System configuration
CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
RM=rm -rf
PROTOC = protoc

# Define where the *.proto files are located.
PROTO_DIR = proto

# Define output directory in which to place the build results.
PROTO_GEN_DIR = src/generated
OBJECT_DIR = build
BIN_DIR = $(OBJECT_DIR)

# Define directories to include.
INC_DIR = -Isrc \
          -Isrc/external \
          -Isrc/external/CMSIS/Include \
          -Isrc/external/CMSIS/Device/ST/STM32F4xx/Include \
          -Isrc/external/STM32F4xx_HAL_Driver/Inc \
          -Isrc/generated \
          -Iembeddedproto/src

# Find all the proto files.
# Extend this for subfolders.
PROTO_FILES = $(wildcard $(PROTO_DIR)/*.proto)

# Convert the names of the proto files to the name of the generated header files.
PROTO_HDR := $(PROTO_FILES:%.proto=$(PROTO_GEN_DIR)/%.h) 


# Define source and object files.
SRC := $(wildcard src/*.c) \
       $(wildcard src/external/*.c) \
       $(wildcard src/external/STM32F4xx_HAL_Driver/Src/*.c) \
       $(wildcard src/external/*.s) \
       $(wildcard src/*.cpp)

# Create the object file names.
OBJS := $(SRC:%.c=$(OBJECT_DIR)/%.o) 
OBJS := $(OBJS:%.cpp=$(OBJECT_DIR)/%.o)
OBJS := $(OBJS:%.s=$(OBJECT_DIR)/%.o)
OBJS := $(OBJS:%.S=$(OBJECT_DIR)/%.o)


# These are the source files from the EmbeddedProto project.
# These are the files that support your messages.
EMBEDDED_PROTO_DIR = $(shell pwd)/embeddedproto
EMBEDDED_PROTO_SRC := $(wildcard ./embeddedproto/src/*.cpp)

EMBEDDED_PROTO_OBJS := $(EMBEDDED_PROTO_SRC:%.cpp=$(OBJECT_DIR)/%.o)
########################
# TODO
#EMBEDDED_PROTO_OBJS := $(EMBEDDED_PROTO_OBJS:../%=$(OBJECT_DIR)/%)
########################

# Assembler, Compiler and Linker flags and linker script settings
LINKER_FLAGS=-lm -mthumb -mhard-float -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -T$(LINK_SCRIPT) -static  -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group -specs=nano.specs -specs=nosys.specs  -Wl,-cref "-Wl,-Map=$(BIN_DIR)/${PROJECT}.map" -Wl,--defsym=malloc_getpagesize_P=0x1000
LINK_SCRIPT="src/external/stm32_flash.ld"
ASSEMBLER_FLAGS=-c -g -O0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -mhard-float -specs=nano.specs -D"STM32F446xx"  -x assembler-with-cpp ${INC_DIR}
COMPILER_FLAGS=-c -g -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -O0 -Wall -mthumb -mhard-float -specs=nano.specs -D"STM32F446xx" ${INC_DIR}
CXXCOMPILER_FLAGS=-std=c++14 -fno-threadsafe-statics -c -g -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -O0 -Wall -mthumb -mhard-float -specs=nano.specs -fno-exceptions -fno-rtti -D"STM32F446xx" ${INC_DIR}



###############
# Build project
# Major targets
###############
.PHONY: all generate debug clean

all: generate debug

generate: 
	$(PROTOC) --plugin=protoc-gen-eams=$(EMBEDDED_PROTO_DIR)/protoc-gen-eams -I$(PROTO_DIR) --eams_out=$(PROTO_GEN_DIR) $(PROTO_DIR)/reply.proto
	$(PROTOC) --plugin=protoc-gen-eams=$(EMBEDDED_PROTO_DIR)/protoc-gen-eams -I$(PROTO_DIR) --eams_out=$(PROTO_GEN_DIR) $(PROTO_DIR)/request.proto

debug:
	make buildelf

buildelf: $(EMBEDDED_PROTO_OBJS) $(OBJS) 
	$(CXX) -o "$(BIN_DIR)/${PROJECT}.elf" $(EMBEDDED_PROTO_OBJS) $(OBJS) $(LINKER_FLAGS)

clean:
	$(info sources: $(EMBEDDED_PROTO_OBJS) $(SRC))
	$(info end)
	$(RM) $(EMBEDDED_PROTO_OBJS) $(OBJS) "$(BIN_DIR)/${PROJECT}.elf" "$(BIN_DIR)/${PROJECT}.map"


##################
# Specific targets
##################
$(OBJECT_DIR)/src/main.o: src/main.cpp
	$(shell mkdir -p $(dir $@))
	$(CXX) $(CXXCOMPILER_FLAGS) src/main.cpp -o $(OBJECT_DIR)/src/main.o 


##################
# Implicit targets
##################

# This rulle is used to generate the message source files based on the *.proto files.


$(OBJECT_DIR)/%.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(COMPILER_FLAGS) $< -o $@

$(OBJECT_DIR)/%.o: %.cpp
	$(shell mkdir -p $(dir $@))
	$(CXX) $(CXXCOMPILER_FLAGS) $< -o $@

$(OBJECT_DIR)/%.o: ../%.cpp
	$(shell mkdir -p $(dir $@))
	$(CXX) $(CXXCOMPILER_FLAGS) $< -o $@

$(OBJECT_DIR)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(CC) $(ASSEMBLER_FLAGS) $< -o $@

$(OBJECT_DIR)/%.o: %.S
	$(shell mkdir -p $(dir $@))
	$(CC) $(ASSEMBLER_FLAGS) $< -o $@
