
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>


class node {
    private:
        ros::NodeHandle *n;
    public:
        node(int argc2, char **argv2) {
            n = NULL;
            ros::init(argc2, argv2, "Publish_2");
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
        
        ros::Subscriber sub;
	ros::Publisher chatter_pub;

    public:
        void setup(int argc1, char **argv1) 
	{
            node myNode( argc1, argv1);
            myNode.create();
            chatter_pub = myNode.getHandle().advertise<std_msgs::String>("chatter", 1000);
            sub = myNode.getHandle().subscribe("chatter", 1000, &coordinator::chatterCallback,this);
	   ros::Rate loop_rate(10);
		loop_rate.sleep();
        }
        void chatterCallback(const std_msgs::String::ConstPtr& msg)
	{
		  long int x=0;
		   
		  std_msgs::String msg1;

		    std::stringstream ss1 (msg->data.c_str());
		    ss1 >> x;
		    x=x*x;

		  std::stringstream ss2;
		    ss2 <<x;
		    msg1.data = ss2.str(); 
   
		  ROS_INFO("%s", msg1.data.c_str());

		  chatter_pub.publish(msg1);

		  
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
		ros::Publisher chatter_pub;
		ros::NodeHandle n;
	public :
		P_n_S ()
		{
			sub = n.subscribe("chatter_by_talker_listener", 1000,&P_n_S::chatterCallback,this);
			chatter_pub = n.advertise<std_msgs::String>("chatter_by_listener_talker", 1000);
		}
		void chatterCallback(const std_msgs::String::ConstPtr& msg);
};
void P_n_S::chatterCallback(const std_msgs::String::ConstPtr& msg)
		{
		  int x=0;

		  std_msgs::String msg1;

		    std::stringstream ss1 (msg->data.c_str());
		    ss1 >> x;
		    x*=x;

		  std::stringstream ss2;
		    ss2 << x;
		    msg1.data = ss2.str(); 
   
		  ROS_INFO("%s", msg1.data.c_str());

		  chatter_pub.publish(msg1);
		}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "publish_2");
  
  P_n_S obj ;
  ros::spin();
  return 0;
}

*/

