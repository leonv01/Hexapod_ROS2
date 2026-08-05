#include "hexapod_gait/hexapod_ik.hpp"

#include <algorithm>
#include <cmath>

namespace hexapod_gait {

std::array<double, 3> HexapodIk::solve_ik(const std::array<double, 3> &target)
{
    double x = target[0];
    double y = target[1];
    double z = target[2];

    double theta1 = std::atan2(y, x);
    double L = std::sqrt(x * x + y * y) - COXA_LENGTH;
    double alpha = std::atan2(z, L);

    double c = std::sqrt(L * L + z * z);

    double cos_t3 = (FEMUR_LENGTH * FEMUR_LENGTH + TIBIA_LENGTH * TIBIA_LENGTH - c * c) /
                    (2.0 * FEMUR_LENGTH * TIBIA_LENGTH);
    cos_t3 = std::clamp(cos_t3, -1.0, 1.0);
    double theta3 = std::acos(cos_t3) - M_PI;

    double cos_beta = (c * c + FEMUR_LENGTH * FEMUR_LENGTH - TIBIA_LENGTH * TIBIA_LENGTH) /
                      (2.0 * c * FEMUR_LENGTH);
    cos_beta = std::clamp(cos_beta, -1.0, 1.0);
    double beta = std::acos(cos_beta);
    double theta2 = alpha + beta;

    return { theta1, theta2, theta3 };
}

} // namespace hexapod_gait