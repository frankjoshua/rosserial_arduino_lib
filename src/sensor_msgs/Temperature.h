#ifndef _ROS_sensor_msgs_Temperature_h
#define _ROS_sensor_msgs_Temperature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

    static const char sensor_msgs_Temperature_type[] PROGMEM= "sensor_msgs/Temperature";
    static const char sensor_msgs_Temperature_md5[] PROGMEM= "ff71b307acdbe7c871a5a6d7ed359100";
  class Temperature : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef float _variance_type;
      _variance_type variance;

    Temperature():
      header(),
      temperature(0),
      variance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->variance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->variance));
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)sensor_msgs_Temperature_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_Temperature_md5);return md5_msg; };

  };

}
#endif
