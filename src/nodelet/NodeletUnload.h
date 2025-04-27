#ifndef _ROS_SERVICE_NodeletUnload_h
#define _ROS_SERVICE_NodeletUnload_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nodelet
{

static const char NODELETUNLOAD[] PROGMEM= "nodelet/NodeletUnload";

    static const char nodelet_NodeletUnloadRequest_type[] PROGMEM= "nodelet/NodeletUnloadRequest";
    static const char nodelet_NodeletUnloadRequest_md5[] PROGMEM= "c1f3d28f1b044c871e6eff2e9fc3c667";
  class NodeletUnloadRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;

    NodeletUnloadRequest():
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)NODELETUNLOAD);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nodelet_NodeletUnloadRequest_md5);return md5_msg; };

  };

    static const char nodelet_NodeletUnloadResponse_type[] PROGMEM= "nodelet/NodeletUnloadResponse";
    static const char nodelet_NodeletUnloadResponse_md5[] PROGMEM= "358e233cde0c8a8bcfea4ce193f8fc15";
  class NodeletUnloadResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    NodeletUnloadResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)NODELETUNLOAD);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nodelet_NodeletUnloadResponse_md5);return md5_msg; };

  };

  class NodeletUnload {
    public:
    typedef NodeletUnloadRequest Request;
    typedef NodeletUnloadResponse Response;
  };

}
#endif
