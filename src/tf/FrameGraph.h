#ifndef _ROS_SERVICE_FrameGraph_h
#define _ROS_SERVICE_FrameGraph_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tf
{

static const char FRAMEGRAPH[] PROGMEM= "tf/FrameGraph";

    static const char tf_FrameGraphRequest_type[] PROGMEM= "tf/FrameGraphRequest";
    static const char tf_FrameGraphRequest_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class FrameGraphRequest : public ros::Msg
  {
    public:

    FrameGraphRequest()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)FRAMEGRAPH);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)tf_FrameGraphRequest_md5);return md5_msg; };

  };

    static const char tf_FrameGraphResponse_type[] PROGMEM= "tf/FrameGraphResponse";
    static const char tf_FrameGraphResponse_md5[] PROGMEM= "c4af9ac907e58e906eb0b6e3c58478c0";
  class FrameGraphResponse : public ros::Msg
  {
    public:
      typedef const char* _dot_graph_type;
      _dot_graph_type dot_graph;

    FrameGraphResponse():
      dot_graph("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_dot_graph = strlen(this->dot_graph);
      varToArr(outbuffer + offset, length_dot_graph);
      offset += 4;
      memcpy(outbuffer + offset, this->dot_graph, length_dot_graph);
      offset += length_dot_graph;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_dot_graph;
      arrToVar(length_dot_graph, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dot_graph; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dot_graph-1]=0;
      this->dot_graph = (char *)(inbuffer + offset-1);
      offset += length_dot_graph;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)FRAMEGRAPH);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)tf_FrameGraphResponse_md5);return md5_msg; };

  };

  class FrameGraph {
    public:
    typedef FrameGraphRequest Request;
    typedef FrameGraphResponse Response;
  };

}
#endif
