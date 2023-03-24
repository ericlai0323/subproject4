#include "../include/velocity_restriction.h"
#include "../include/kalman_filter.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "CommandVelocityCorrectionPublilsher");
    ros::NodeHandle n;
    ros::NodeHandle nh_priv("~");
    CommandVelocityRestriction CommandVelocityRestrictor;
    ros::Subscriber CommandVelocitySubsriber = n.subscribe("cmd_vel", 200, &CommandVelocityRestriction::CommandVelocityCallBack, &CommandVelocityRestrictor);
    ros::Publisher CommandVelocityRestrictPublisher = n.advertise<geometry_msgs::Twist>("cmd_vel/correct", 200);

    // ros::Rate loop_rate(50); // publish rate of 50 Hz

    ROS_INFO_STREAM("CommandVelocityCorrection Start");

    while (ros::ok())
    {
        // publish the corrected velocity values
        CommandVelocityRestrictPublisher.publish(CommandVelocityRestrictor.CommandVelocityRestrict);

        // spin once to process any pending callbacks
        ros::spinOnce();

        // sleep to maintain the desired publish rate
        // loop_rate.sleep();
    }

    return 0;
}