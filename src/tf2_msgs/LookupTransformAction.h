#ifndef _ROS_tf2_msgs_LookupTransformAction_h
#define _ROS_tf2_msgs_LookupTransformAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tf2_msgs/LookupTransformActionGoal.h"
#include "tf2_msgs/LookupTransformActionResult.h"
#include "tf2_msgs/LookupTransformActionFeedback.h"

namespace tf2_msgs
{

    static const char tf2_msgs_LookupTransformAction_type[] PROGMEM= "tf2_msgs/LookupTransformAction";
    static const char tf2_msgs_LookupTransformAction_md5[] PROGMEM= "7ee01ba91a56c2245c610992dbaa3c37";
  class LookupTransformAction : public ros::Msg
  {
    public:
      typedef tf2_msgs::LookupTransformActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef tf2_msgs::LookupTransformActionResult _action_result_type;
      _action_result_type action_result;
      typedef tf2_msgs::LookupTransformActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    LookupTransformAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)tf2_msgs_LookupTransformAction_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)tf2_msgs_LookupTransformAction_md5);return md5_msg; };

  };

}
#endif
