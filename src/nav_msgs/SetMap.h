#ifndef _ROS_SERVICE_SetMap_h
#define _ROS_SERVICE_SetMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "nav_msgs/OccupancyGrid.h"

namespace nav_msgs
{

static const char SETMAP[] PROGMEM= "nav_msgs/SetMap";

    static const char nav_msgs_SetMapRequest_type[] PROGMEM= "nav_msgs/SetMapRequest";
    static const char nav_msgs_SetMapRequest_md5[] PROGMEM= "91149a20d7be299b87c340df8cc94fd4";
  class SetMapRequest : public ros::Msg
  {
    public:
      typedef nav_msgs::OccupancyGrid _map_type;
      _map_type map;
      typedef geometry_msgs::PoseWithCovarianceStamped _initial_pose_type;
      _initial_pose_type initial_pose;

    SetMapRequest():
      map(),
      initial_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      offset += this->initial_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
      offset += this->initial_pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)SETMAP);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_SetMapRequest_md5);return md5_msg; };

  };

    static const char nav_msgs_SetMapResponse_type[] PROGMEM= "nav_msgs/SetMapResponse";
    static const char nav_msgs_SetMapResponse_md5[] PROGMEM= "358e233cde0c8a8bcfea4ce193f8fc15";
  class SetMapResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetMapResponse():
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)SETMAP);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_SetMapResponse_md5);return md5_msg; };

  };

  class SetMap {
    public:
    typedef SetMapRequest Request;
    typedef SetMapResponse Response;
  };

}
#endif
