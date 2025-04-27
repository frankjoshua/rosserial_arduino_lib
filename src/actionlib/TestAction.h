#ifndef _ROS_actionlib_TestAction_h
#define _ROS_actionlib_TestAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "actionlib/TestActionGoal.h"
#include "actionlib/TestActionResult.h"
#include "actionlib/TestActionFeedback.h"

namespace actionlib
{

    static const char actionlib_TestAction_type[] PROGMEM= "actionlib/TestAction";
    static const char actionlib_TestAction_md5[] PROGMEM= "991e87a72802262dfbe5d1b3cf6efc9a";
  class TestAction : public ros::Msg
  {
    public:
      typedef actionlib::TestActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef actionlib::TestActionResult _action_result_type;
      _action_result_type action_result;
      typedef actionlib::TestActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    TestAction():
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)actionlib_TestAction_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)actionlib_TestAction_md5);return md5_msg; };

  };

}
#endif
