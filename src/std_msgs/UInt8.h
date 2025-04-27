#ifndef _ROS_std_msgs_UInt8_h
#define _ROS_std_msgs_UInt8_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

    static const char std_msgs_UInt8_type[] PROGMEM= "std_msgs/UInt8";
    static const char std_msgs_UInt8_md5[] PROGMEM= "7c8164229e7d2c17eb95e9231617fdee";
  class UInt8 : public ros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;

    UInt8():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)std_msgs_UInt8_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_msgs_UInt8_md5);return md5_msg; };

  };

}
#endif
