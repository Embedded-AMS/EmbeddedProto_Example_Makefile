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
#ifndef _REPLY_H_
#define _REPLY_H_

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedField.h>

namespace demo
{

class A final: public ::EmbeddedProto::MessageInterface
{
  public:
    A() :
        x_(),
        y_(),
        z_()
    {

    };
    ~A() override = default;

    enum class id
    {
      NOT_SET = 0,
      X = 1,
      Y = 2,
      Z = 3
    };

    inline EmbeddedProto::uint32::FIELD_TYPE x() const { return x_.get(); }
    inline void clear_x() { x_.set(0U); }
    inline void set_x(const EmbeddedProto::uint32::FIELD_TYPE& value) { x_.set(value); }
    inline void set_x(const EmbeddedProto::uint32::FIELD_TYPE&& value) { x_.set(value); }
    inline EmbeddedProto::uint32::FIELD_TYPE get_x() const { return x_.get(); }

    inline EmbeddedProto::uint32::FIELD_TYPE y() const { return y_.get(); }
    inline void clear_y() { y_.set(0U); }
    inline void set_y(const EmbeddedProto::uint32::FIELD_TYPE& value) { y_.set(value); }
    inline void set_y(const EmbeddedProto::uint32::FIELD_TYPE&& value) { y_.set(value); }
    inline EmbeddedProto::uint32::FIELD_TYPE get_y() const { return y_.get(); }

    inline EmbeddedProto::uint32::FIELD_TYPE z() const { return z_.get(); }
    inline void clear_z() { z_.set(0U); }
    inline void set_z(const EmbeddedProto::uint32::FIELD_TYPE& value) { z_.set(value); }
    inline void set_z(const EmbeddedProto::uint32::FIELD_TYPE&& value) { z_.set(value); }
    inline EmbeddedProto::uint32::FIELD_TYPE get_z() const { return z_.get(); }

    bool serialize(::EmbeddedProto::WriteBufferInterface& buffer) const final
    {
      bool result = true;

      if((0U != x_.get()) && result)
      {
        result = x_.serialize_with_id(static_cast<uint32_t>(id::X), buffer);
      }  

      if((0U != y_.get()) && result)
      {
        result = y_.serialize_with_id(static_cast<uint32_t>(id::Y), buffer);
      }  

      if((0U != z_.get()) && result)
      {
        result = z_.serialize_with_id(static_cast<uint32_t>(id::Z), buffer);
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
          case static_cast<uint32_t>(id::X):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              result = x_.deserialize(buffer);
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          case static_cast<uint32_t>(id::Y):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              result = y_.deserialize(buffer);
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          case static_cast<uint32_t>(id::Z):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              result = z_.deserialize(buffer);
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
      clear_x();
      clear_y();
      clear_z();
    }

  private:

    EmbeddedProto::uint32 x_;
    EmbeddedProto::uint32 y_;
    EmbeddedProto::uint32 z_;

};

class B final: public ::EmbeddedProto::MessageInterface
{
  public:
    B() :
        u_(),
        v_(),
        w_()
    {

    };
    ~B() override = default;

    enum class id
    {
      NOT_SET = 0,
      U = 1,
      V = 2,
      W = 3
    };

    inline EmbeddedProto::doublefixed::FIELD_TYPE u() const { return u_.get(); }
    inline void clear_u() { u_.set(0.0); }
    inline void set_u(const EmbeddedProto::doublefixed::FIELD_TYPE& value) { u_.set(value); }
    inline void set_u(const EmbeddedProto::doublefixed::FIELD_TYPE&& value) { u_.set(value); }
    inline EmbeddedProto::doublefixed::FIELD_TYPE get_u() const { return u_.get(); }

    inline EmbeddedProto::doublefixed::FIELD_TYPE v() const { return v_.get(); }
    inline void clear_v() { v_.set(0.0); }
    inline void set_v(const EmbeddedProto::doublefixed::FIELD_TYPE& value) { v_.set(value); }
    inline void set_v(const EmbeddedProto::doublefixed::FIELD_TYPE&& value) { v_.set(value); }
    inline EmbeddedProto::doublefixed::FIELD_TYPE get_v() const { return v_.get(); }

    inline EmbeddedProto::doublefixed::FIELD_TYPE w() const { return w_.get(); }
    inline void clear_w() { w_.set(0.0); }
    inline void set_w(const EmbeddedProto::doublefixed::FIELD_TYPE& value) { w_.set(value); }
    inline void set_w(const EmbeddedProto::doublefixed::FIELD_TYPE&& value) { w_.set(value); }
    inline EmbeddedProto::doublefixed::FIELD_TYPE get_w() const { return w_.get(); }

    bool serialize(::EmbeddedProto::WriteBufferInterface& buffer) const final
    {
      bool result = true;

      if((0.0 != u_.get()) && result)
      {
        result = u_.serialize_with_id(static_cast<uint32_t>(id::U), buffer);
      }  

      if((0.0 != v_.get()) && result)
      {
        result = v_.serialize_with_id(static_cast<uint32_t>(id::V), buffer);
      }  

      if((0.0 != w_.get()) && result)
      {
        result = w_.serialize_with_id(static_cast<uint32_t>(id::W), buffer);
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
          case static_cast<uint32_t>(id::U):
          {
            if(::EmbeddedProto::WireFormatter::WireType::FIXED64 == wire_type)
            {
              result = u_.deserialize(buffer);
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          case static_cast<uint32_t>(id::V):
          {
            if(::EmbeddedProto::WireFormatter::WireType::FIXED64 == wire_type)
            {
              result = v_.deserialize(buffer);
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          case static_cast<uint32_t>(id::W):
          {
            if(::EmbeddedProto::WireFormatter::WireType::FIXED64 == wire_type)
            {
              result = w_.deserialize(buffer);
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
      clear_u();
      clear_v();
      clear_w();
    }

  private:

    EmbeddedProto::doublefixed u_;
    EmbeddedProto::doublefixed v_;
    EmbeddedProto::doublefixed w_;

};

class reply final: public ::EmbeddedProto::MessageInterface
{
  public:
    reply() :
        msgId_(),
        which_type_(id::NOT_SET)
    {

    };
    ~reply() override = default;

    enum class id
    {
      NOT_SET = 0,
      MSGID = 1,
      A = 2,
      B = 3
    };

    inline EmbeddedProto::uint32::FIELD_TYPE msgId() const { return msgId_.get(); }
    inline void clear_msgId() { msgId_.set(0U); }
    inline void set_msgId(const EmbeddedProto::uint32::FIELD_TYPE& value) { msgId_.set(value); }
    inline void set_msgId(const EmbeddedProto::uint32::FIELD_TYPE&& value) { msgId_.set(value); }
    inline EmbeddedProto::uint32::FIELD_TYPE get_msgId() const { return msgId_.get(); }

    id get_which_type() const { return which_type_; }

    inline const demo::A& a() const { return type_.a_; }
    inline void clear_a()
    {
      if(id::A == which_type_)
      {
        which_type_ = id::NOT_SET;
        type_.a_.~A();
      }
    }
    inline void set_a(const demo::A& value)
    {
      if(id::A != which_type_)
      {
        init_type(id::A);
      }
      type_.a_ = value;
    }
    inline void set_a(const demo::A&& value)
    {
      if(id::A != which_type_)
      {
        init_type(id::A);
      }
      type_.a_ = value;
    }
    inline demo::A& mutable_a()
    {
      if(id::A != which_type_)
      {
        init_type(id::A);
      }
      return type_.a_;
    }
    inline const demo::A& get_a() const { return type_.a_; }

    inline const demo::B& b() const { return type_.b_; }
    inline void clear_b()
    {
      if(id::B == which_type_)
      {
        which_type_ = id::NOT_SET;
        type_.b_.~B();
      }
    }
    inline void set_b(const demo::B& value)
    {
      if(id::B != which_type_)
      {
        init_type(id::B);
      }
      type_.b_ = value;
    }
    inline void set_b(const demo::B&& value)
    {
      if(id::B != which_type_)
      {
        init_type(id::B);
      }
      type_.b_ = value;
    }
    inline demo::B& mutable_b()
    {
      if(id::B != which_type_)
      {
        init_type(id::B);
      }
      return type_.b_;
    }
    inline const demo::B& get_b() const { return type_.b_; }

    bool serialize(::EmbeddedProto::WriteBufferInterface& buffer) const final
    {
      bool result = true;

      if((0U != msgId_.get()) && result)
      {
        result = msgId_.serialize_with_id(static_cast<uint32_t>(id::MSGID), buffer);
      }  

      switch(which_type_)
      {
        case id::A:
          if(result)
            {
              result = type_.a_.serialize_with_id(static_cast<uint32_t>(id::A), buffer);
            }
             
          break;

        case id::B:
          if(result)
            {
              result = type_.b_.serialize_with_id(static_cast<uint32_t>(id::B), buffer);
            }
             
          break;

        default:
          break;
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

          case static_cast<uint32_t>(id::A):
          {
            if(::EmbeddedProto::WireFormatter::WireType::LENGTH_DELIMITED == wire_type)
            {
              uint32_t size;
              result = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, size);
              ::EmbeddedProto::ReadBufferSection bufferSection(buffer, size);
              init_type(id::A);
              result = result && type_.a_.deserialize(bufferSection);
              if(result)
              {
                which_type_ = id::A;
              }
            }
            else
            {
              // TODO Error wire type does not match field.
              result = false;
            } 
            break;
          }

          case static_cast<uint32_t>(id::B):
          {
            if(::EmbeddedProto::WireFormatter::WireType::LENGTH_DELIMITED == wire_type)
            {
              uint32_t size;
              result = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, size);
              ::EmbeddedProto::ReadBufferSection bufferSection(buffer, size);
              init_type(id::B);
              result = result && type_.b_.deserialize(bufferSection);
              if(result)
              {
                which_type_ = id::B;
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
      clear_type();
    }

  private:

    EmbeddedProto::uint32 msgId_;

    id which_type_;
    union type
    {
      type() {}
      ~type() {}
      demo::A a_;
      demo::B b_;
    };
    type type_;

    void init_type(const id field_id)
    {
      if(id::NOT_SET != which_type_)
      {
        // First delete the old object in the oneof.
        clear_type();
      }

      // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
      switch(field_id)
      {
        case id::A:
          new(&type_.a_) demo::A;
          which_type_ = id::A;
          break;
        case id::B:
          new(&type_.b_) demo::B;
          which_type_ = id::B;
          break;
        default:
          break;
       }
    }

    void clear_type()
    {
      switch(which_type_)
      {
        case id::A:
          type_.a_.~A();
          break;
        case id::B:
          type_.b_.~B();
          break;
        default:
          break;
      }
      which_type_ = id::NOT_SET;
    }

};

} // End of namespace demo
#endif // _REPLY_H_
