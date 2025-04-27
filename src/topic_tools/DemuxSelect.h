#ifndef _ROS_SERVICE_DemuxSelect_h
#define _ROS_SERVICE_DemuxSelect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace topic_tools
{

static const char DEMUXSELECT[] PROGMEM= "topic_tools/DemuxSelect";

    static const char topic_tools_DemuxSelectRequest_type[] PROGMEM= "topic_tools/DemuxSelectRequest";
    static const char topic_tools_DemuxSelectRequest_md5[] PROGMEM= "d8f94bae31b356b24d0427f80426d0c3";
  class DemuxSelectRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    DemuxSelectRequest():
      topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)DEMUXSELECT);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)topic_tools_DemuxSelectRequest_md5);return md5_msg; };

  };

    static const char topic_tools_DemuxSelectResponse_type[] PROGMEM= "topic_tools/DemuxSelectResponse";
    static const char topic_tools_DemuxSelectResponse_md5[] PROGMEM= "3db0a473debdbafea387c9e49358c320";
  class DemuxSelectResponse : public ros::Msg
  {
    public:
      typedef const char* _prev_topic_type;
      _prev_topic_type prev_topic;

    DemuxSelectResponse():
      prev_topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_prev_topic = strlen(this->prev_topic);
      varToArr(outbuffer + offset, length_prev_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->prev_topic, length_prev_topic);
      offset += length_prev_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_prev_topic;
      arrToVar(length_prev_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prev_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prev_topic-1]=0;
      this->prev_topic = (char *)(inbuffer + offset-1);
      offset += length_prev_topic;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)DEMUXSELECT);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)topic_tools_DemuxSelectResponse_md5);return md5_msg; };

  };

  class DemuxSelect {
    public:
    typedef DemuxSelectRequest Request;
    typedef DemuxSelectResponse Response;
  };

}
#endif
