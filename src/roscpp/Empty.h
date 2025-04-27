#ifndef _ROS_SERVICE_Empty_h
#define _ROS_SERVICE_Empty_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roscpp
{

static const char EMPTY[] PROGMEM= "roscpp/Empty";

    static const char roscpp_EmptyRequest_type[] PROGMEM= "roscpp/EmptyRequest";
    static const char roscpp_EmptyRequest_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class EmptyRequest : public ros::Msg
  {
    public:

    EmptyRequest()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)EMPTY);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)roscpp_EmptyRequest_md5);return md5_msg; };

  };

    static const char roscpp_EmptyResponse_type[] PROGMEM= "roscpp/EmptyResponse";
    static const char roscpp_EmptyResponse_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class EmptyResponse : public ros::Msg
  {
    public:

    EmptyResponse()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)EMPTY);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)roscpp_EmptyResponse_md5);return md5_msg; };

  };

  class Empty {
    public:
    typedef EmptyRequest Request;
    typedef EmptyResponse Response;
  };

}
#endif
