#ifndef _ROS_tf2_msgs_LookupTransformFeedback_h
#define _ROS_tf2_msgs_LookupTransformFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tf2_msgs
{

    static const char tf2_msgs_LookupTransformFeedback_type[] PROGMEM= "tf2_msgs/LookupTransformFeedback";
    static const char tf2_msgs_LookupTransformFeedback_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class LookupTransformFeedback : public ros::Msg
  {
    public:

    LookupTransformFeedback()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)tf2_msgs_LookupTransformFeedback_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)tf2_msgs_LookupTransformFeedback_md5);return md5_msg; };

  };

}
#endif
