#ifndef SERVO_COMMAND_HPP_
#define SERVO_COMMAND_HPP_

namespace hexapod_hardware
{
struct ServoCommand 
{
    unsigned int leg;
    double angle;
};

}

#endif // SERVO_COMMAND_HPP_