
![alt text](https://embeddedproto.com/wp-content/uploads/2020/03/Embedded-Proto-e1583834233386.png "Embedded Proto Logo")


Copyrights 2020-2022 Embedded AMS B.V. Amsterdam, [www.EmbeddedAMS.nl](https://www.EmbeddedAMS.nl), [info@EmbeddedAMS.nl](mailto:info@EmbeddedAMS.nl)


Looking for a more elaborate description of this example? Please visit: https://embeddedproto.com/how-to-set-up-a-project-with-embeddedproto-using-makefiles/

# Introduction 

This is a simple demo of a makefile toolchain for a STM 32bit ARM microcontroller. The goal of this demo is to demonstrate a possible method to generate Embedded Proto sourcecode and use it in a project. 


# Installation

1. Install STM32CubeIDE if you have not already.
2. Install the dependencies required by Embedded Proto. They are listed [here](https://github.com/Embedded-AMS/EmbeddedProto).
3. Checkout this example repository including the submodule of Embedded Proto: `git clone --recursive https://github.com/Embedded-AMS/EmbeddedProto_Example_Makefile.git`.
4. Next setup the virtual environment for Embedded Proto by entering the folder and running the `python setup.py` script.


# Folder layout

After generating and building the code this folder (stm32f4xx) the folling sub folders will be present:
* build \- The binary output of the makefiles
* proto \- The location where the .proto files are located
* src \- The sourcecode folder
  ** external \- Sourcecode of the STM HAL and ARM CMSIS
  ** generated \- This folder is created during the source code generation step. It includes the code generated by the Embedded Proto plugin for the .proto files.


# Build steps

The build is devided into two steps:
1. Generating the sourcecode for the .proto files.
2. Build the sourcecode

These steps are executed using the script `run_build.sh`

The makefile assumes that the code has been generated. It includes the generated sourcecode folder (src/generated) just like any other.


# Sourcecode

The *main.cpp* holds a very simple infinte loop which over and over sets a new value in the protobuf message.
