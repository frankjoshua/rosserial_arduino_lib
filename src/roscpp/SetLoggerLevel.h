#ifndef _ROS_SERVICE_SetLoggerLevel_h
#define _ROS_SERVICE_SetLoggerLevel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace roscpp
{

#ifdef ESP8266
    static const char SETLOGGERLEVEL[] = "roscpp/SetLoggerLevel";
#else
    static const char SETLOGGERLEVEL[] PROGMEM = "roscpp/SetLoggerLevel";
#endif

  class SetLoggerLevelRequest : public ros::Msg
  {
    public:
      typedef const char* _logger_type;
      _logger_type logger;
      typedef const char* _level_type;
      _level_type level;

    SetLoggerLevelRequest():
      logger(""),
      level("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_logger = strlen(this->logger);
      varToArr(outbuffer + offset, length_logger);
      offset += 4;
      memcpy(outbuffer + offset, this->logger, length_logger);
      offset += length_logger;
      uint32_t length_level = strlen(this->level);
      varToArr(outbuffer + offset, length_level);
      offset += 4;
      memcpy(outbuffer + offset, this->level, length_level);
      offset += length_level;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_logger;
      arrToVar(length_logger, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_logger; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_logger-1]=0;
      this->logger = (char *)(inbuffer + offset-1);
      offset += length_logger;
      uint32_t length_level;
      arrToVar(length_level, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_level; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_level-1]=0;
      this->level = (char *)(inbuffer + offset-1);
      offset += length_level;
     return offset;
    }

    const char * getType(){ return SETLOGGERLEVEL; };
    #ifdef ESP8266
        const char * getMD5() { return  ("51da076440d78ca1684d36c868df61ea");};
    #else
        const char * getMD5() { return  PSTR("51da076440d78ca1684d36c868df61ea");};
    #endif

  };

  class SetLoggerLevelResponse : public ros::Msg
  {
    public:

    SetLoggerLevelResponse()
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

    const char * getType(){ return SETLOGGERLEVEL; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class SetLoggerLevel {
    public:
    typedef SetLoggerLevelRequest Request;
    typedef SetLoggerLevelResponse Response;
  };

}
#endif
