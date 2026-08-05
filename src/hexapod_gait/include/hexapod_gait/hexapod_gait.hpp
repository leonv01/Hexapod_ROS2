#ifndef HEXAPOD_GAIT_HPP_
#define HEXAPOD_GAIT_HPP_

#include "hexapod_gait/hexapod_ik.hpp"

#include "gait_strategy/gait_strategy.hpp"

#include <rclcpp/rclcpp.hpp>
#include <memory>

namespace hexapod_gait
{
class HexapodGait : public rclcpp::Node
{
public:
    HexapodGait();
private:
    std::unique_ptr<GaitStrategy> gait_strategy;
};
}
#endif // HEXAPOD_GAIT_HPP_
