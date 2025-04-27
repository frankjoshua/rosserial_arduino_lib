#ifndef _ROS_geometry_msgs_PolygonStamped_h
#define _ROS_geometry_msgs_PolygonStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Polygon.h"

namespace geometry_msgs
{

    static const char geometry_msgs_PolygonStamped_type[] PROGMEM= "geometry_msgs/PolygonStamped";
    static const char geometry_msgs_PolygonStamped_md5[] PROGMEM= "c6be8f7dc3bee7fe9e8d296070f53340";
  class PolygonStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Polygon _polygon_type;
      _polygon_type polygon;

    PolygonStamped():
      header(),
      polygon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_PolygonStamped_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_PolygonStamped_md5);return md5_msg; };

  };

}
#endif
