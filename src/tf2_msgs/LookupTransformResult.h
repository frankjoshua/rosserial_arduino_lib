#ifndef _ROS_tf2_msgs_LookupTransformResult_h
#define _ROS_tf2_msgs_LookupTransformResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_msgs/TF2Error.h"

namespace tf2_msgs
{

    static const char tf2_msgs_LookupTransformResult_type[] PROGMEM= "tf2_msgs/LookupTransformResult";
    static const char tf2_msgs_LookupTransformResult_md5[] PROGMEM= "3fe5db6a19ca9cfb675418c5ad875c36";
  class LookupTransformResult : public ros::Msg
  {
    public:
      typedef geometry_msgs::TransformStamped _transform_type;
      _transform_type transform;
      typedef tf2_msgs::TF2Error _error_type;
      _error_type error;

    LookupTransformResult():
      transform(),
      error()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->transform.serialize(outbuffer + offset);
      offset += this->error.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->transform.deserialize(inbuffer + offset);
      offset += this->error.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)tf2_msgs_LookupTransformResult_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)tf2_msgs_LookupTransformResult_md5);return md5_msg; };

  };

}
#endif
