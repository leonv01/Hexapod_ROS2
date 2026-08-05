#ifndef GAIT_STRATEGY_HPP_
#define GAIT_STRATEGY_HPP_

#include <unordered_map>
#include <algorithm>

namespace hexapod_gait
{

struct LegData
{
    double coxa_joint_;
    double tibia_joint_;
    double femur_joint_;
};

enum LEG
{
    LF_LEG,
    LM_LEG,
    LR_LEG,

    RF_LEG,
    RM_LEG,
    RR_LEG
};

class GaitStrategy
{
public:
    virtual ~GaitStrategy() = default;

    virtual void propagate_gait(int step) = 0;
    virtual LegData propagate_leg(LEG leg, int step) = 0;
    virtual LegData get_leg(LEG leg_id) {
        auto idx = leg_map_.find(leg_id);
        LegData leg = { 0.0, 0.0, 0.0 };

        if (idx != leg_map_.end())
        {
            leg = idx->second;
        }

        return leg;
    }

private:
    std::unordered_map<LEG, LegData> leg_map_;
};

}

#endif // GAIT_STRATEGY_HPP_