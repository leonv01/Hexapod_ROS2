#include <cstdio>

#include "hexapod_gait/hexapod_gait.hpp"

#include "gait_factory/gait_factory.hpp"

#include <string>

namespace hexapod_gait
{

HexapodGait::HexapodGait() : rclcpp::Node("hexapod_gait_node")
{
  std::string strategy = "wave_gait";
  gait_strategy = std::move(GaitFactory::create_gait(strategy));
}

}

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  printf("hello world hexapod_gait package\n");
  return 0;
}
