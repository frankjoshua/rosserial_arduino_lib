#ifndef _ROS_dynamic_reconfigure_DoubleParameter_h
#define _ROS_dynamic_reconfigure_DoubleParameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace dynamic_reconfigure
{

  class DoubleParameter : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef float _value_type;
      _value_type value;

    DoubleParameter():
      name(""),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    #ifdef ESP8266
        const char * getType() { return  ("dynamic_reconfigure/DoubleParameter");};
    #else
        const char * getType() { return  PSTR("dynamic_reconfigure/DoubleParameter");};
    #endif
    #ifdef ESP8266
        const char * getMD5() { return  ("d8512f27253c0f65f928a67c329cd658");};
    #else
        const char * getMD5() { return  PSTR("d8512f27253c0f65f928a67c329cd658");};
    #endif

  };

}
#endif
