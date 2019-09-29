#ifndef _ROS_SERVICE_GetMap_h
#define _ROS_SERVICE_GetMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "nav_msgs/OccupancyGrid.h"

namespace nav_msgs
{

#ifdef ESP8266
    static const char GETMAP[] = "nav_msgs/GetMap";
#else
    static const char GETMAP[] PROGMEM = "nav_msgs/GetMap";
#endif

  class GetMapRequest : public ros::Msg
  {
    public:

    GetMapRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETMAP; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class GetMapResponse : public ros::Msg
  {
    public:
      typedef nav_msgs::OccupancyGrid _map_type;
      _map_type map;

    GetMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETMAP; };
    #ifdef ESP8266
        const char * getMD5() { return  ("6cdd0a18e0aff5b0a3ca2326a89b54ff");};
    #else
        const char * getMD5() { return  PSTR("6cdd0a18e0aff5b0a3ca2326a89b54ff");};
    #endif

  };

  class GetMap {
    public:
    typedef GetMapRequest Request;
    typedef GetMapResponse Response;
  };

}
#endif
