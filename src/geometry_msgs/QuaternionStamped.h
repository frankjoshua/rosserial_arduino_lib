#ifndef _ROS_geometry_msgs_QuaternionStamped_h
#define _ROS_geometry_msgs_QuaternionStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"

namespace geometry_msgs
{

    static const char geometry_msgs_QuaternionStamped_type[] PROGMEM= "geometry_msgs/QuaternionStamped";
    static const char geometry_msgs_QuaternionStamped_md5[] PROGMEM= "e57f1e547e0e1fd13504588ffc8334e2";
  class QuaternionStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Quaternion _quaternion_type;
      _quaternion_type quaternion;

    QuaternionStamped():
      header(),
      quaternion()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->quaternion.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->quaternion.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_QuaternionStamped_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_QuaternionStamped_md5);return md5_msg; };

  };

}
#endif
