#ifndef HEXAPOD_IK_HPP_
#define HEXAPOD_IK_HPP_

#include <array>

namespace hexapod_gait {

class HexapodIk
{
public:
    std::array<double, 3> solve_ik(const std::array<double, 3> &target);

private:
    const double COXA_LENGTH = 0.040;      // 40.0 mm
    const double FEMUR_LENGTH = 0.075208;  // 75.208 mm
    const double TIBIA_LENGTH = 0.098265;  // 98.265 mm
};

} // namespace hexapod_gait

#endif // HEXAPOD_IK_HPP_