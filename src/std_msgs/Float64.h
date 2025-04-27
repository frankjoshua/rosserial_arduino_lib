#ifndef _ROS_std_msgs_Float64_h
#define _ROS_std_msgs_Float64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

    static const char std_msgs_Float64_type[] PROGMEM= "std_msgs/Float64";
    static const char std_msgs_Float64_md5[] PROGMEM= "fdb28210bfa9d7c91146260178d9a584";
  class Float64 : public ros::Msg
  {
    public:
      typedef float _data_type;
      _data_type data;

    Float64():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->data));
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)std_msgs_Float64_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_msgs_Float64_md5);return md5_msg; };

  };

}
#endif
