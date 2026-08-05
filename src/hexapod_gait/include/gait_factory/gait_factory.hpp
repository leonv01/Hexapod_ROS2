#ifndef GAIT_FACTORY_HPP_
#define GAIT_FACTORY_HPP_

#include "gait_strategy/gait_strategy.hpp"
#include <string>
#include <memory>

namespace hexapod_gait
{

class GaitFactory
{
public:
    static std::unique_ptr<GaitStrategy> create_gait(std::string &type);
};

}

#endif // GAIT_FACTORY_HPP_