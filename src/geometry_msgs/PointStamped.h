#ifndef _ROS_geometry_msgs_PointStamped_h
#define _ROS_geometry_msgs_PointStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace geometry_msgs
{

    static const char geometry_msgs_PointStamped_type[] PROGMEM= "geometry_msgs/PointStamped";
    static const char geometry_msgs_PointStamped_md5[] PROGMEM= "c63aecb41bfdfd6b7e1fac37c7cbe7bf";
  class PointStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _point_type;
      _point_type point;

    PointStamped():
      header(),
      point()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->point.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_PointStamped_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_PointStamped_md5);return md5_msg; };

  };

}
#endif
