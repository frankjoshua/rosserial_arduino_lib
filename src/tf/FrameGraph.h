#ifndef _ROS_SERVICE_FrameGraph_h
#define _ROS_SERVICE_FrameGraph_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace tf
{

#ifdef ESP8266
    static const char FRAMEGRAPH[] = "tf/FrameGraph";
#else
    static const char FRAMEGRAPH[] PROGMEM = "tf/FrameGraph";
#endif

  class FrameGraphRequest : public ros::Msg
  {
    public:

    FrameGraphRequest()
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

    const char * getType(){ return FRAMEGRAPH; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d41d8cd98f00b204e9800998ecf8427e");};
    #else
        const char * getMD5() { return  PSTR("d41d8cd98f00b204e9800998ecf8427e");};
    #endif

  };

  class FrameGraphResponse : public ros::Msg
  {
    public:
      typedef const char* _dot_graph_type;
      _dot_graph_type dot_graph;

    FrameGraphResponse():
      dot_graph("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_dot_graph = strlen(this->dot_graph);
      varToArr(outbuffer + offset, length_dot_graph);
      offset += 4;
      memcpy(outbuffer + offset, this->dot_graph, length_dot_graph);
      offset += length_dot_graph;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
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

    const char * getType(){ return FRAMEGRAPH; };
    #ifdef ESP8266
        const char * getMD5() { return  ("c4af9ac907e58e906eb0b6e3c58478c0");};
    #else
        const char * getMD5() { return  PSTR("c4af9ac907e58e906eb0b6e3c58478c0");};
    #endif

  };

  class FrameGraph {
    public:
    typedef FrameGraphRequest Request;
    typedef FrameGraphResponse Response;
  };

}
#endif
