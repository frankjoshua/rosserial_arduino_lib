#ifndef _ROS_bond_Constants_h
#define _ROS_bond_Constants_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bond
{

    static const char bond_Constants_type[] PROGMEM= "bond/Constants";
    static const char bond_Constants_md5[] PROGMEM= "6fc594dc1d7bd7919077042712f8c8b0";
  class Constants : public ros::Msg
  {
    public:
      enum { DEAD_PUBLISH_PERIOD =  0.05 };
      enum { DEFAULT_CONNECT_TIMEOUT =  10.0 };
      enum { DEFAULT_HEARTBEAT_TIMEOUT =  4.0 };
      enum { DEFAULT_DISCONNECT_TIMEOUT =  2.0 };
      enum { DEFAULT_HEARTBEAT_PERIOD =  1.0 };
      enum { DISABLE_HEARTBEAT_TIMEOUT_PARAM = /bond_disable_heartbeat_timeout };

    Constants()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)bond_Constants_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)bond_Constants_md5);return md5_msg; };

  };

}
#endif
