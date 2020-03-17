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

// This file is generated. Please do not edit!
#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedField.h>

namespace demo
{

enum types
{
  A = 0,
  B = 1
};


class request final: public ::EmbeddedProto::MessageInterface
{
  public:
    request() :
        msgId_(),
        selection_(static_cast<demo::types>(0))
    {

    };
    ~request() override = default;

    enum class id
    {
      NOT_SET = 0,
      MSGID = 1,
      SELECTION = 2
    };

    inline EmbeddedProto::uint32::FIELD_TYPE msgId() const { return msgId_.get(); }
    inline void clear_msgId() { msgId_.set(0U); }
    inline void set_msgId(const EmbeddedProto::uint32::FIELD_TYPE& value) { msgId_.set(value); }
    inline void set_msgId(const EmbeddedProto::uint32::FIELD_TYPE&& value) { msgId_.set(value); }
    inline EmbeddedProto::uint32::FIELD_TYPE get_msgId() const { return msgId_.get(); }

    inline demo::types selection() const { return selection_; }
    inline void clear_selection() { selection_ = static_cast<demo::types>(static_cast<demo::types>(0)); }
    inline void set_selection(const demo::types& value) { selection_ = value; }
    inline void set_selection(const demo::types&& value) { selection_ = value; }
        inline demo::types get_selection() const { return selection_; }

    bool serialize(::EmbeddedProto::WriteBufferInterface& buffer) const final
    {
      bool result = true;

      if((0U != msgId_.get()) && result)
      {
        result = msgId_.serialize_with_id(static_cast<uint32_t>(id::MSGID), buffer);
      }  

      if((static_cast<demo::types>(0) != selection_) && result)
      {
        EmbeddedProto::uint32 value;
        value.set(static_cast<uint32_t>(selection_));
        result = value.serialize_with_id(static_cast<uint32_t>(id::SELECTION), buffer);
      }
       

      return result;
    };

    bool deserialize(::EmbeddedProto::ReadBufferInterface& buffer) final
    {
      bool result = true;
      ::EmbeddedProto::WireFormatter::WireType wire_type;
      uint32_t id_number = 0;

      while(result && ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number))
      {
        switch(id_number)
        {
          case static_cast<uint32_t>(id::MSGID):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              result = msgId_.deserialize(buffer);
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          case static_cast<uint32_t>(id::SELECTION):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value;
              result = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(result)
              {
                set_selection(static_cast<demo::types>(value));
              }
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          default:
            break;
        }
      }
      return result;
    };

    void clear() final
    {
      clear_msgId();
      clear_selection();
    }

  private:

    EmbeddedProto::uint32 msgId_;
    demo::types selection_;

};

} // End of namespace demo
#endif // _REQUEST_H_
