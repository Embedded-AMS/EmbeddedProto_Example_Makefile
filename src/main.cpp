
// Includes 
#include <stm32f4xx.h>

#include <main.h>

#include <reply.h>
#include <request.h>
#include <DemoWriteBuffer.h>
#include <DemoReadBuffer.h>

// Construction of the messages.
demo::reply reply_msg;
demo::request request_msg;

// Construction of the write and read buffer objects.
demo::WriteBuffer<50> send_buffer;
demo::ReadBuffer read_buffer;

int main(void)
{
  SystemInit();
  
  uint32_t request_counter = 0;

  while (1)
  {
    // Increment the request counter each iteration and alternate between request A and B.
    request_msg.set_msgId(++request_counter);
    request_msg.set_selection((request_counter & 0x01) ? demo::types::A
                                                       : demo::types::B);

    if(::EmbeddedProto::Error::NO_ERRORS == request_msg.serialize(send_buffer))
    {
      // Serialization is successful. We can now use the buffer to send the data via a peripheral.
    }
    else
    {
      // Serialization failed for some reason.
    }

    // For demo purposes manually set the demo data.
    if(request_counter & 0x01)
    {
      // Data for A
      constexpr uint32_t RESPONS_SIZE_A = 10;
      uint8_t demo_response_A[RESPONS_SIZE_A] = {0x08, 0x01, 0x12, 0x06, 0x08, 0x0A, 0x10, 0x14,
          0x18, 0x1E};

      read_buffer.set_demo_data(demo_response_A, RESPONS_SIZE_A);
    }
    else
    {
      // Data for B
      constexpr uint32_t RESPONS_SIZE_B = 31;
      uint8_t demo_response_B[RESPONS_SIZE_B] = {0x08, 0x02, 0x1A, 0x1B, 0x09, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x59, 0x40, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x40,
        0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x72, 0x40};

      read_buffer.set_demo_data(demo_response_B, RESPONS_SIZE_B);
    }

    // Obtain from the buffer the reply message.
    if(::EmbeddedProto::Error::NO_ERRORS == reply_msg.deserialize(read_buffer))
    {
      // Now we can use it.
      switch(reply_msg.get_which_type())
      {
        case demo::reply::FieldNumber::A:
        {
          // Do something with the data.
          uint32_t ans_a = reply_msg.a().x() + reply_msg.a().y() + reply_msg.a().z();
          break;
        }

        case demo::reply::FieldNumber::B:
        {
          // Do something with the data.
          uint32_t ans_b = reply_msg.b().u() * reply_msg.b().v() * reply_msg.b().w();
          break;
        }

        default:
          break;
      }
    }
  }
}
