#ifndef _ROS_std_msgs_Empty_h
#define _ROS_std_msgs_Empty_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

    static const char std_msgs_Empty_type[] PROGMEM= "std_msgs/Empty";
    static const char std_msgs_Empty_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class Empty : public ros::Msg
  {
    public:

    Empty()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)std_msgs_Empty_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_msgs_Empty_md5);return md5_msg; };

  };

}
#endif
