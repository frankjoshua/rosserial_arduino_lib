#ifndef _ROS_SERVICE_DemuxAdd_h
#define _ROS_SERVICE_DemuxAdd_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace topic_tools
{

#ifdef ESP8266
    static const char DEMUXADD[] = "topic_tools/DemuxAdd";
#else
    static const char DEMUXADD[] PROGMEM = "topic_tools/DemuxAdd";
#endif

  class DemuxAddRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    DemuxAddRequest():
      topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
     return offset;
    }

    const char * getType(){ return DEMUXADD; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d8f94bae31b356b24d0427f80426d0c3");};
    #else
        const char * getMD5() { return  PSTR("d8f94bae31b356b24d0427f80426d0c3");};
    #endif

  };

  class DemuxAddResponse : public ros::Msg
  {
    public:

    DemuxAddResponse()
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

    const char * getType(){ return DEMUXADD; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class DemuxAdd {
    public:
    typedef DemuxAddRequest Request;
    typedef DemuxAddResponse Response;
  };

}
#endif
