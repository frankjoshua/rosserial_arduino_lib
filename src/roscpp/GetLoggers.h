#ifndef _ROS_SERVICE_GetLoggers_h
#define _ROS_SERVICE_GetLoggers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"
#include "roscpp/Logger.h"

namespace roscpp
{

#ifdef ESP8266
    static const char GETLOGGERS[] = "roscpp/GetLoggers";
#else
    static const char GETLOGGERS[] PROGMEM = "roscpp/GetLoggers";
#endif

  class GetLoggersRequest : public ros::Msg
  {
    public:

    GetLoggersRequest()
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

    const char * getType(){ return GETLOGGERS; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class GetLoggersResponse : public ros::Msg
  {
    public:
      uint32_t loggers_length;
      typedef roscpp::Logger _loggers_type;
      _loggers_type st_loggers;
      _loggers_type * loggers;

    GetLoggersResponse():
      loggers_length(0), loggers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->loggers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loggers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loggers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loggers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loggers_length);
      for( uint32_t i = 0; i < loggers_length; i++){
      offset += this->loggers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t loggers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      loggers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      loggers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      loggers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->loggers_length);
      if(loggers_lengthT > loggers_length)
        this->loggers = (roscpp::Logger*)realloc(this->loggers, loggers_lengthT * sizeof(roscpp::Logger));
      loggers_length = loggers_lengthT;
      for( uint32_t i = 0; i < loggers_length; i++){
      offset += this->st_loggers.deserialize(inbuffer + offset);
        memcpy( &(this->loggers[i]), &(this->st_loggers), sizeof(roscpp::Logger));
      }
     return offset;
    }

    const char * getType(){ return GETLOGGERS; };
    #ifdef ESP8266
        const char * getMD5() { return  ("32e97e85527d4678a8f9279894bb64b0");};
    #else
        const char * getMD5() { return  PSTR("32e97e85527d4678a8f9279894bb64b0");};
    #endif

  };

  class GetLoggers {
    public:
    typedef GetLoggersRequest Request;
    typedef GetLoggersResponse Response;
  };

}
#endif
