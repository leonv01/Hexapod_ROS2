#ifndef RIPLE_GAIT_CONCRETE_HPP_
#define RIPLE_GAIT_CONCRETE_HPP_

#include "gait_strategy/gait_strategy.hpp"

namespace hexapod_gait
{

class RipleGaitConcrete : public GaitStrategy
{
public:
    void propagate_gait(int step) override;
    LegData propagate_leg(LEG leg, int step) override;
};

}

#endif // RIPLE_GAIT_CONCRETE_HPP_