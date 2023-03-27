#include "velocity_restriction.h"

void CommandVelocityRestriction::CommandVelocityCallBack(const geometry_msgs::Twist &msg)
{
    CommandVelocity = msg;

    // Velocity Correction, make sure velocity biggger than min velocity
    if (abs(CommandVelocity.linear.x) < MinLinearVelocityX && CommandVelocity.linear.x != 0)
    {
        CommandVelocity.linear.x = (CommandVelocity.linear.x > 0) ? MinLinearVelocityX : -MinLinearVelocityX;
    }

    if (abs(CommandVelocity.angular.z) < MinAngularVelocityZ && CommandVelocity.angular.z != 0)
    {
        CommandVelocity.angular.z = (CommandVelocity.angular.z > 0) ? MinAngularVelocityZ : -MinAngularVelocityZ;
    }
    CommandVelocityRestrict = CommandVelocity;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "CommandVelocityRestrictionPublilsher");
    ros::NodeHandle n;
    ros::NodeHandle nh_priv("~");
    CommandVelocityRestriction CommandVelocityRestrictor;
    ros::Subscriber CommandVelocitySubsriber = n.subscribe("cmd_vel", 200, &CommandVelocityRestriction::CommandVelocityCallBack, &CommandVelocityRestrictor);
    ros::Publisher CommandVelocityRestrictPublisher = n.advertise<geometry_msgs::Twist>("cmd_vel/correct", 200);

    // ros::Rate loop_rate(50); // publish rate of 50 Hz

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
