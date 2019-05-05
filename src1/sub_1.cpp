
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

class node {
    private:
        ros::NodeHandle *n;
    public:
        node(int argc2, char **argv2) {
            n = NULL;
            ros::init(argc2, argv2, "Subscriber_1");
        }

        void create() 
	{
        if (n == NULL) 
	{
        n = new ros::NodeHandle();
        }
        }

    ros::NodeHandle getHandle() {return *n;}
};

class coordinator
{
    private:
        
        ros::Subscriber sub1;
	ros::Subscriber sub2;

    public:
        void setup(int argc1, char **argv1) 
	{
            node myNode( argc1, argv1);
            myNode.create();
            sub1 = myNode.getHandle().subscribe("chatter", 1000, &coordinator::chatterCallback,this);
	    sub2 = myNode.getHandle().subscribe("chatter1", 1000, &coordinator::chatterCallback,this);
        }
        void chatterCallback(const std_msgs::String::ConstPtr& msg)
	{
		ROS_INFO("[%s]", msg->data.c_str());
	}
};


int main(int argc, char **argv)
{
	coordinator obj;
	obj.setup(argc, argv);
	ros::spin();
	return 0;
}	

















/**
class P_n_S
{
	private : 
		ros::Subscriber sub ;
		ros::NodeHandle n;
	public :
		P_n_S ()
		{
			sub = n.subscribe("chatter_by_talker_listener", 1000,boost::bind(&P_n_S::chatterCallback, this, _1));
			
		}
		void chatterCallback(const std_msgs::String::ConstPtr& msg);
};
void P_n_S::chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
// %EndTag(CALLBACK)%

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "subscriber_1");

  
  P_n_S obj;

  
  ros::spin();
  
  return 0;
}
// %EndTag(FULLTEXT)%
*/
