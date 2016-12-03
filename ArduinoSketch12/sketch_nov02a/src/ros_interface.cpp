#include "ros_interface.h"

#include <ros.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>

#if 0
ros::NodeHandle nh;

ros::Subscriber<std_msgs::UInt8> subEmo("control_emo", control_emo );
ros::Subscriber<std_msgs::UInt8> setBright("face_bright", set_brightness );
ros::Subscriber<std_msgs::UInt8> setMode("face_mode", set_mode);
ros::Subscriber<std_msgs::String> subTalk("SaraVoice", talk);

void control_emo(const std_msgs::UInt8& emo)
{
	switch (emo.data) 
	{
	    case 1:
	      emo_content();
	      break;
	    case 2:
	      emo_triste();
	      break;
	    case 3:
	      emo_ciconspect();
	      break;
	    case 4:
	      emo_fache();
	      break;
	    case 5:
	      emo_surpris();
	      break;
	    case 6:
	      emo_coquin();
	      break;
	    case 7:
	      emo_party();
	      break;
	    default:
	      emo_content();
	}
}

void init_ros_interface(void)
{
  nh.initNode();
  //nh.subscribe(subMouth);
  //nh.subscribe(subEye);
  nh.subscribe(subEmo);
  nh.subscribe(setBright);
  nh.subscribe(setMode);
  nh.subscribe(subTalk);
}

//Just as an example
void loop() 
{
  if(mode == 0)
  { 
    
  }
  else if (mode == 1)
  {
    openFade();
    mode = 3;
  }
  else if(mode == 2)
  {
    loadingRoll2();
    smile(60,60,60);
  }
  else if(mode == 3)
  {
    emo_content();
    mode = 0;
  }
  else if(mode == 4)
  {
    emo_ciconspect();
    mode = 0;
  }
  else if(mode == 5)
  {
    emo_fache();
    mode = 0;
  }
  else if (mode == 6)
  {
    emo_wait();
    mode = 0;
  }
  nh.spinOnce();
}

#endif