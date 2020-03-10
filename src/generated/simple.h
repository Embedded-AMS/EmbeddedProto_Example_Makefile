// This file is generated. Please do not edit!
#ifndef _SIMPLE_H_
#define _SIMPLE_H_

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedField.h>

class data final: public ::EmbeddedProto::MessageInterface
{
  public:
    data() :
        x_(),
        y_(),
        z_()
    {

    };
    ~data() override = default;

    enum class id
    {
      NOT_SET = 0,
      X = 1,
      Y = 2,
      Z = 3
    };

    inline EmbeddedProto::int32::FIELD_TYPE x() const { return x_.get(); }
    inline void clear_x() { x_.set(0); }
    inline void set_x(const EmbeddedProto::int32::FIELD_TYPE& value) { x_.set(value); }
    inline void set_x(const EmbeddedProto::int32::FIELD_TYPE&& value) { x_.set(value); }
    inline EmbeddedProto::int32::FIELD_TYPE get_x() const { return x_.get(); }

    inline EmbeddedProto::int32::FIELD_TYPE y() const { return y_.get(); }
    inline void clear_y() { y_.set(0); }
    inline void set_y(const EmbeddedProto::int32::FIELD_TYPE& value) { y_.set(value); }
    inline void set_y(const EmbeddedProto::int32::FIELD_TYPE&& value) { y_.set(value); }
    inline EmbeddedProto::int32::FIELD_TYPE get_y() const { return y_.get(); }

    inline EmbeddedProto::int32::FIELD_TYPE z() const { return z_.get(); }
    inline void clear_z() { z_.set(0); }
    inline void set_z(const EmbeddedProto::int32::FIELD_TYPE& value) { z_.set(value); }
    inline void set_z(const EmbeddedProto::int32::FIELD_TYPE&& value) { z_.set(value); }
    inline EmbeddedProto::int32::FIELD_TYPE get_z() const { return z_.get(); }

    bool serialize(::EmbeddedProto::WriteBufferInterface& buffer) const final
    {
      bool result = true;

      if((0 != x_.get()) && result)
      {
        result = x_.serialize(static_cast<uint32_t>(id::X), buffer);
      }  

      if((0 != y_.get()) && result)
      {
        result = y_.serialize(static_cast<uint32_t>(id::Y), buffer);
      }  

      if((0 != z_.get()) && result)
      {
        result = z_.serialize(static_cast<uint32_t>(id::Z), buffer);
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

    EmbeddedProto::int32 x_;
    EmbeddedProto::int32 y_;
    EmbeddedProto::int32 z_;

};

#endif // _SIMPLE_H_
