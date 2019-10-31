#ifndef _ROS_SERVICE_Empty_h
#define _ROS_SERVICE_Empty_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace std_srvs
{

#ifdef ESP8266
    static const char EMPTY[] = "std_srvs/Empty";
#else
    static const char EMPTY[] PROGMEM = "std_srvs/Empty";
#endif

  class EmptyRequest : public ros::Msg
  {
    public:

    EmptyRequest()
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

    const char * getType(){ return EMPTY; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class EmptyResponse : public ros::Msg
  {
    public:

    EmptyResponse()
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

    const char * getType(){ return EMPTY; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class Empty {
    public:
    typedef EmptyRequest Request;
    typedef EmptyResponse Response;
  };

}
#endif
