#ifndef _ROS_geometry_msgs_Twist_h
#define _ROS_geometry_msgs_Twist_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace geometry_msgs
{

    static const char geometry_msgs_Twist_type[] PROGMEM= "geometry_msgs/Twist";
    static const char geometry_msgs_Twist_md5[] PROGMEM= "9f195f881246fdfa2798d1d3eebca84a";
  class Twist : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _linear_type;
      _linear_type linear;
      typedef geometry_msgs::Vector3 _angular_type;
      _angular_type angular;

    Twist():
      linear(),
      angular()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->linear.serialize(outbuffer + offset);
      offset += this->angular.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->linear.deserialize(inbuffer + offset);
      offset += this->angular.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_Twist_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_Twist_md5);return md5_msg; };

  };

}
#endif
