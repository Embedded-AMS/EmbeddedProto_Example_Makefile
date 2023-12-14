/*
 *  Copyright (C) 2020-2024 Embedded AMS B.V. - All Rights Reserved
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
 *    Atoomweg 2
 *    1627 LE, Hoorn
 *    the Netherlands
 */

#ifndef _DEMO_READ_BUFFER_H_
#define _DEMO_READ_BUFFER_H_

#include <ReadBufferInterface.h>
#include <stdio.h>

namespace demo
{
  class ReadBuffer : public EmbeddedProto::ReadBufferInterface
  {
    public:
      ReadBuffer()
        : index_(0),
          size_(0),
          bytes_{0U}
      {

      }

      virtual ~ReadBuffer() = default;

      uint32_t get_size() const override
      {
        return index_;
      }

      uint32_t get_max_size() const override
      {
        return size_;
      }

      void set_demo_data(uint8_t* bytes, const uint32_t size)
      {
        bytes_ = bytes;
        size_ = size;
      }

      bool peek(uint8_t& byte) const override
      {
        bool result = index_ < size_;
        if(result)
        {
          byte = bytes_[index_];
        }
        return result;
      }

      bool advance() override
      {
        bool result = false;
        if(index_ < size_)
        {
          ++index_;
          result = true;
        }
        return result;
      }

      bool advance(const uint32_t N) override
      {
        bool result = false;
        index_ += N;
        if(index_ >= size_)
        {
          index_ = size_;
          result = true;
        }
        return result;
      }

      bool pop(uint8_t& byte) override
      {
        bool result = index_ < size_;
        if(result)
        {
          byte = bytes_[index_];
          ++index_;
        }
        return result;
      }

    private:

      uint32_t index_;
      uint32_t size_;
      uint8_t* bytes_;

  };

} // End of namespace DEMO


#endif // _DEMO_READ_BUFFER_H_
