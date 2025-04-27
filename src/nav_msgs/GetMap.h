#ifndef _ROS_SERVICE_GetMap_h
#define _ROS_SERVICE_GetMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/OccupancyGrid.h"

namespace nav_msgs
{

static const char GETMAP[] PROGMEM= "nav_msgs/GetMap";

    static const char nav_msgs_GetMapRequest_type[] PROGMEM= "nav_msgs/GetMapRequest";
    static const char nav_msgs_GetMapRequest_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class GetMapRequest : public ros::Msg
  {
    public:

    GetMapRequest()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)GETMAP);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_GetMapRequest_md5);return md5_msg; };

  };

    static const char nav_msgs_GetMapResponse_type[] PROGMEM= "nav_msgs/GetMapResponse";
    static const char nav_msgs_GetMapResponse_md5[] PROGMEM= "6cdd0a18e0aff5b0a3ca2326a89b54ff";
  class GetMapResponse : public ros::Msg
  {
    public:
      typedef nav_msgs::OccupancyGrid _map_type;
      _map_type map;

    GetMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)GETMAP);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_GetMapResponse_md5);return md5_msg; };

  };

  class GetMap {
    public:
    typedef GetMapRequest Request;
    typedef GetMapResponse Response;
  };

}
#endif
