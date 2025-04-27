#ifndef _ROS_geometry_msgs_Transform_h
#define _ROS_geometry_msgs_Transform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"

namespace geometry_msgs
{

    static const char geometry_msgs_Transform_type[] PROGMEM= "geometry_msgs/Transform";
    static const char geometry_msgs_Transform_md5[] PROGMEM= "ac9eff44abf714214112b05d54a3cf9b";
  class Transform : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _translation_type;
      _translation_type translation;
      typedef geometry_msgs::Quaternion _rotation_type;
      _rotation_type rotation;

    Transform():
      translation(),
      rotation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->translation.serialize(outbuffer + offset);
      offset += this->rotation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->translation.deserialize(inbuffer + offset);
      offset += this->rotation.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_Transform_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_Transform_md5);return md5_msg; };

  };

}
#endif
