#ifndef MOCK_CONCRETE_HPP_
#define MOCK_CONCRETE_HPP_

#include "hal_strategy/servo_strategy.hpp"
#include "hal_data/servo_command.hpp"
#include "rclcpp/rclcpp.hpp"

#include <unordered_map>

namespace hexapod_hardware
{
class MockConcrete : public ServoStrategy
{
public:
    MockConcrete();

    bool initialize() override;

    void set_angle_rad(ServoCommand &servo_command) override;
    void set_angle_degree(ServoCommand &servo_command) override;

    bool get_angle_rad(ServoCommand &servo_command) override;

    void shutdown() override;

private:
    rclcpp::Logger logger_;
    std::unordered_map<unsigned int, double> mock_angles_;
};
}

#endif // MOCK_CONCRETE_HPP_