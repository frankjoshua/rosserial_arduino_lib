#ifndef _ROS_geometry_msgs_AccelWithCovariance_h
#define _ROS_geometry_msgs_AccelWithCovariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Accel.h"

namespace geometry_msgs
{

    static const char geometry_msgs_AccelWithCovariance_type[] PROGMEM= "geometry_msgs/AccelWithCovariance";
    static const char geometry_msgs_AccelWithCovariance_md5[] PROGMEM= "ad5a718d699c6be72a02b8d6a139f334";
  class AccelWithCovariance : public ros::Msg
  {
    public:
      typedef geometry_msgs::Accel _accel_type;
      _accel_type accel;
      float covariance[36];

    AccelWithCovariance():
      accel(),
      covariance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->accel.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->accel.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariance[i]));
      }
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_AccelWithCovariance_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_AccelWithCovariance_md5);return md5_msg; };

  };

}
#endif
