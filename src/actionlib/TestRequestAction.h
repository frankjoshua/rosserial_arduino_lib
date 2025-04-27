#ifndef _ROS_actionlib_TestRequestAction_h
#define _ROS_actionlib_TestRequestAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "actionlib/TestRequestActionGoal.h"
#include "actionlib/TestRequestActionResult.h"
#include "actionlib/TestRequestActionFeedback.h"

namespace actionlib
{

    static const char actionlib_TestRequestAction_type[] PROGMEM= "actionlib/TestRequestAction";
    static const char actionlib_TestRequestAction_md5[] PROGMEM= "dc44b1f4045dbf0d1db54423b3b86b30";
  class TestRequestAction : public ros::Msg
  {
    public:
      typedef actionlib::TestRequestActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef actionlib::TestRequestActionResult _action_result_type;
      _action_result_type action_result;
      typedef actionlib::TestRequestActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    TestRequestAction():
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)actionlib_TestRequestAction_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)actionlib_TestRequestAction_md5);return md5_msg; };

  };

}
#endif
