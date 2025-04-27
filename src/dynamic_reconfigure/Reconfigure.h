#ifndef _ROS_SERVICE_Reconfigure_h
#define _ROS_SERVICE_Reconfigure_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamic_reconfigure/Config.h"

namespace dynamic_reconfigure
{

static const char RECONFIGURE[] PROGMEM= "dynamic_reconfigure/Reconfigure";

    static const char dynamic_reconfigure_ReconfigureRequest_type[] PROGMEM= "dynamic_reconfigure/ReconfigureRequest";
    static const char dynamic_reconfigure_ReconfigureRequest_md5[] PROGMEM= "ac41a77620a4a0348b7001641796a8a1";
  class ReconfigureRequest : public ros::Msg
  {
    public:
      typedef dynamic_reconfigure::Config _config_type;
      _config_type config;

    ReconfigureRequest():
      config()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->config.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)RECONFIGURE);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)dynamic_reconfigure_ReconfigureRequest_md5);return md5_msg; };

  };

    static const char dynamic_reconfigure_ReconfigureResponse_type[] PROGMEM= "dynamic_reconfigure/ReconfigureResponse";
    static const char dynamic_reconfigure_ReconfigureResponse_md5[] PROGMEM= "ac41a77620a4a0348b7001641796a8a1";
  class ReconfigureResponse : public ros::Msg
  {
    public:
      typedef dynamic_reconfigure::Config _config_type;
      _config_type config;

    ReconfigureResponse():
      config()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->config.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)RECONFIGURE);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)dynamic_reconfigure_ReconfigureResponse_md5);return md5_msg; };

  };

  class Reconfigure {
    public:
    typedef ReconfigureRequest Request;
    typedef ReconfigureResponse Response;
  };

}
#endif
