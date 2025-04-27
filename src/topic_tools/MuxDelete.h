#ifndef _ROS_SERVICE_MuxDelete_h
#define _ROS_SERVICE_MuxDelete_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace topic_tools
{

static const char MUXDELETE[] PROGMEM= "topic_tools/MuxDelete";

    static const char topic_tools_MuxDeleteRequest_type[] PROGMEM= "topic_tools/MuxDeleteRequest";
    static const char topic_tools_MuxDeleteRequest_md5[] PROGMEM= "d8f94bae31b356b24d0427f80426d0c3";
  class MuxDeleteRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    MuxDeleteRequest():
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)MUXDELETE);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)topic_tools_MuxDeleteRequest_md5);return md5_msg; };

  };

    static const char topic_tools_MuxDeleteResponse_type[] PROGMEM= "topic_tools/MuxDeleteResponse";
    static const char topic_tools_MuxDeleteResponse_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class MuxDeleteResponse : public ros::Msg
  {
    public:

    MuxDeleteResponse()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)MUXDELETE);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)topic_tools_MuxDeleteResponse_md5);return md5_msg; };

  };

  class MuxDelete {
    public:
    typedef MuxDeleteRequest Request;
    typedef MuxDeleteResponse Response;
  };

}
#endif
