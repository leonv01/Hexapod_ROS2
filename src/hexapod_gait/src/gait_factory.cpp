#include "gait_factory/gait_factory.hpp"

#include "gait_strategy/riple_gait_concrete.hpp"
#include "gait_strategy/wave_gait_concrete.hpp"

namespace hexapod_gait
{

std::unique_ptr<GaitStrategy> GaitFactory::create_gait(std::string &type)
{
    if (type == "wave_gait")
    {
        return std::make_unique<WaveGaitConcrete>();
    }
    else if (type == "riple_gait")
    {
        return std::make_unique<RipleGaitConcrete>();
    }

    return nullptr;
}

}