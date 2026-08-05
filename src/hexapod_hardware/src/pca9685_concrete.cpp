#include "hal_strategy/pca9685_concrete.hpp"

#include <string>
#include <algorithm>

namespace hexapod_hardware
{
PCA9685Concrete::PCA9685Concrete(std::vector<unsigned int> ids_)
{
    const std::string device = "/dev/i2c-1";

    for (auto id : ids_)
    {
        pcas_[id] = std::make_unique<PiPCA9685::PCA9685>(device, id);
        pcas_[id]->set_pwm_freq(FREQUENCY_);
    }

    channel_mapping_ = {
        { 0, std::tuple{ 0x40, 0x00 } },
        { 1, std::tuple{ 0x40, 0x01 } },
        { 2, std::tuple{ 0x40, 0x02 } },

        { 3, std::tuple{ 0x40, 0x04 } },
        { 4, std::tuple{ 0x40, 0x05 } },
        { 5, std::tuple{ 0x40, 0x06 } },

        { 6, std::tuple{ 0x40, 0x08 } },
        { 7, std::tuple{ 0x40, 0x09 } },
        { 8, std::tuple{ 0x40, 0x0A } },

        { 9, std::tuple{ 0x41, 0x00 } },
        { 10, std::tuple{ 0x41, 0x01 } },
        { 11, std::tuple{ 0x41, 0x02 } },

        { 12, std::tuple{ 0x41, 0x04 } },
        { 13, std::tuple{ 0x41, 0x05 } },
        { 14, std::tuple{ 0x41, 0x06 } },

        { 15, std::tuple{ 0x41, 0x0D } },
        { 16, std::tuple{ 0x41, 0x0E } },
        { 17, std::tuple{ 0x41, 0x0F } },
    };
}

bool PCA9685Concrete::initialize() 
{
    return true;
}

void PCA9685Concrete::set_angle_rad(ServoCommand &servo_command) 
{
    auto [address, channel] = channel_mapping_[servo_command.leg];

    unsigned int pwm_tick = rad_to_pwm(servo_command.angle);
    pcas_[address]->set_pwm(channel, 0, pwm_tick);    
}

void PCA9685Concrete::set_angle_degree(ServoCommand &servo_command) 
{
    (void)servo_command;
}

bool PCA9685Concrete::get_angle_rad(ServoCommand &servo_command) 
{
    (void)servo_command;
    return true;
}

void PCA9685Concrete::shutdown() 
{
    for (size_t i = 0; i < 18; i++)
    {
        ServoCommand command{ static_cast<unsigned int>(i), 0.0 };
        set_angle_rad(command);
    }
}

unsigned int PCA9685Concrete::rad_to_pwm(double angle)
{
    double clamp = std::clamp(angle, MIN_RAD_, MAX_RAD_);

    return static_cast<unsigned int>(MIN_TICKS_ + (clamp / MAX_RAD_) * (MAX_TICKS_ - MIN_TICKS_));
}

}