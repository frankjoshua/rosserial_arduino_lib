#ifndef _ROS_dynamic_reconfigure_SensorLevels_h
#define _ROS_dynamic_reconfigure_SensorLevels_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_reconfigure
{

    static const char dynamic_reconfigure_SensorLevels_type[] PROGMEM= "dynamic_reconfigure/SensorLevels";
    static const char dynamic_reconfigure_SensorLevels_md5[] PROGMEM= "6322637bee96d5489db6e2127c47602c";
  class SensorLevels : public ros::Msg
  {
    public:
      enum { RECONFIGURE_CLOSE =  3   };
      enum { RECONFIGURE_STOP =  1   };
      enum { RECONFIGURE_RUNNING =  0  };

    SensorLevels()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)dynamic_reconfigure_SensorLevels_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)dynamic_reconfigure_SensorLevels_md5);return md5_msg; };

  };

}
#endif
