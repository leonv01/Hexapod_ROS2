#include <cstdio>

#include "hexapod_teleop/hexapod_teleop.hpp"

namespace hexapod_teleop
{

HexapodTeleop::HexapodTeleop() : rclcpp::Node("hexapod_teleop_node")
{

}

}

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  printf("hello world hexapod_teleop package\n");
  return 0;
}
