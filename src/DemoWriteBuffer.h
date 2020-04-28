/*
 *  Copyright (C) 2020 Embedded AMS B.V. - All Rights Reserved
 *
 *  This file is part of Embedded Proto.
 *
 *  Embedded Proto is open source software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, version 3 of the license.
 *
 *  Embedded Proto  is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Embedded Proto. If not, see <https://www.gnu.org/licenses/>.
 *
 *  For commercial and closed source application please visit:
 *  <https://EmbeddedProto.com/license/>.
 *
 *  Embedded AMS B.V.
 *  Info:
 *    info at EmbeddedProto dot com
 *
 *  Postal adress:
 *    Johan Huizingalaan 763a
 *    1066 VH, Amsterdam
 *    the Netherlands
 */

#ifndef _DEMO_WRITE_BUFFER_H_
#define _DEMO_WRITE_BUFFER_H_

#include <WriteBufferInterface.h>
#include <stdio.h>

namespace demo
{
  template<uint32_t BUFFER_SIZE>
  class WriteBuffer : public EmbeddedProto::WriteBufferInterface
  {
    public:
      WriteBuffer()
        : bytes_used_(0),
          bytes_{0U}
      {

      }

      virtual ~WriteBuffer() = default;

      void clear() override
      {
        bytes_used_ = 0;
      }

      uint32_t get_size() const override
      {
        return bytes_used_;
      }

      uint32_t get_max_size() const override
      {
        return BUFFER_SIZE;
      }

      uint32_t get_available_size() const override
      {
        return  - bytes_used_;
      }

      bool push(const uint8_t byte) override
      {
        bool result = BUFFER_SIZE > bytes_used_;
        if(result)
        {
          bytes_[bytes_used_] = byte;
          ++bytes_used_;
        }
        return result;
      }

      bool push(const uint8_t* bytes, const uint32_t length) override
      {
        bool result = BUFFER_SIZE >= (bytes_used_ + length);
        if(result)
        {
          memcpy(bytes_ + bytes_used_, bytes, length);
          bytes_used_ += length;
        }
        return result;
      }

    private:

      uint32_t bytes_used_;
      uint8_t bytes_[BUFFER_SIZE];

  };

} // End of namespace DEMO


#endif // _DEMO_WRITE_BUFFER_H_
