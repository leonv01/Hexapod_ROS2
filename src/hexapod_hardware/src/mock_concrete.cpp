#include "hal_strategy/mock_concrete.hpp"
#include <cmath>

namespace hexapod_hardware
{
MockConcrete::MockConcrete() : logger_(rclcpp::get_logger("MockConcrete"))
{
    RCLCPP_INFO(logger_, "MockConcrete hardware strategy instantiated.");
}

bool MockConcrete::initialize() 
{
    RCLCPP_INFO(logger_, "Initializing MockConcrete hardware strategy...");
    return true;
}

void MockConcrete::set_angle_rad(ServoCommand &servo_command) 
{
    mock_angles_[servo_command.leg] = servo_command.angle;
    RCLCPP_INFO(
        logger_, 
        "[MOCK HARDWARE] Servo/Leg [%u] -> Target Angle: %.4f rad (%.2f deg)", 
        servo_command.leg, 
        servo_command.angle, 
        servo_command.angle * (180.0 / M_PI)
    );
}

void MockConcrete::set_angle_degree(ServoCommand &servo_command) 
{
    double rad = servo_command.angle * (M_PI / 180.0);
    ServoCommand cmd{ servo_command.leg, rad };
    set_angle_rad(cmd);
}

bool MockConcrete::get_angle_rad(ServoCommand &servo_command) 
{
    if (mock_angles_.count(servo_command.leg) > 0)
    {
        servo_command.angle = mock_angles_[servo_command.leg];
        return true;
    }
    servo_command.angle = 0.0;
    return false;
}

void MockConcrete::shutdown() 
{
    RCLCPP_INFO(logger_, "MockConcrete hardware strategy shutting down.");
}

}