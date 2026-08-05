#ifndef WAVE_GAIT_CONCRETE_HPP_
#define WAVE_GAIT_CONCRETE_HPP_

#include "gait_strategy/gait_strategy.hpp"

namespace hexapod_gait
{

class WaveGaitConcrete : public GaitStrategy
{
public:
    void propagate_gait(int step) override;
    LegData propagate_leg(LEG leg, int step) override;
};

}

#endif // WAVE_GAIT_CONCRETE_HPP_