#ifndef _ROS_SERVICE_SetLoggerLevel_h
#define _ROS_SERVICE_SetLoggerLevel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscpp
{

static const char SETLOGGERLEVEL[] PROGMEM= "roscpp/SetLoggerLevel";

    static const char roscpp_SetLoggerLevelRequest_type[] PROGMEM= "roscpp/SetLoggerLevelRequest";
    static const char roscpp_SetLoggerLevelRequest_md5[] PROGMEM= "51da076440d78ca1684d36c868df61ea";
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

    virtual int serialize(unsigned char *outbuffer) const override
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

    virtual int deserialize(unsigned char *inbuffer) override
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)SETLOGGERLEVEL);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)roscpp_SetLoggerLevelRequest_md5);return md5_msg; };

  };

    static const char roscpp_SetLoggerLevelResponse_type[] PROGMEM= "roscpp/SetLoggerLevelResponse";
    static const char roscpp_SetLoggerLevelResponse_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class SetLoggerLevelResponse : public ros::Msg
  {
    public:

    SetLoggerLevelResponse()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)SETLOGGERLEVEL);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)roscpp_SetLoggerLevelResponse_md5);return md5_msg; };

  };

  class SetLoggerLevel {
    public:
    typedef SetLoggerLevelRequest Request;
    typedef SetLoggerLevelResponse Response;
  };

}
#endif
