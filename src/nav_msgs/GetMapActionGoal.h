#ifndef _ROS_nav_msgs_GetMapActionGoal_h
#define _ROS_nav_msgs_GetMapActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "nav_msgs/GetMapGoal.h"

namespace nav_msgs
{

    static const char nav_msgs_GetMapActionGoal_type[] PROGMEM= "nav_msgs/GetMapActionGoal";
    static const char nav_msgs_GetMapActionGoal_md5[] PROGMEM= "4b30be6cd12b9e72826df56b481f40e0";
  class GetMapActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef nav_msgs::GetMapGoal _goal_type;
      _goal_type goal;

    GetMapActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)nav_msgs_GetMapActionGoal_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_GetMapActionGoal_md5);return md5_msg; };

  };

}
#endif
