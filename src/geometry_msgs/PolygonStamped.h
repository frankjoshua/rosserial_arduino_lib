#ifndef _ROS_geometry_msgs_PolygonStamped_h
#define _ROS_geometry_msgs_PolygonStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Polygon.h"

namespace geometry_msgs
{

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

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    #ifdef ESP8266
        const char * getType() { return  ("geometry_msgs/PolygonStamped");};
    #else
        const char * getType() { return  PSTR("geometry_msgs/PolygonStamped");};
    #endif
    #ifdef ESP8266
        const char * getMD5() { return  ("c6be8f7dc3bee7fe9e8d296070f53340");};
    #else
        const char * getMD5() { return  PSTR("c6be8f7dc3bee7fe9e8d296070f53340");};
    #endif

  };

}
#endif
