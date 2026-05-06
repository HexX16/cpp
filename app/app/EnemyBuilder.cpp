#pragma once
#include "StatsWeight.h"
#include "EnemyBuilder.h"

StatsWeight build_hook()
{
    StatsWeight stats_weight;
    stats_weight.backpress = 5;
    stats_weight.biceps = 20;
    stats_weight.fingers = 10;
    stats_weight.high_wrist = 5;
    stats_weight.low_wrist = 20;
    stats_weight.pronation = 5;
    stats_weight.rise = 5;
    stats_weight.sidepress = 30;
    stats_weight.supination = 10;
    stats_weight.triceps = 5;
    return stats_weight;
}

StatsWeight build_kingsmove()
{
    StatsWeight stats_weight;
    stats_weight.backpress = 20;
    stats_weight.biceps = 10;
    stats_weight.fingers = 5;
    stats_weight.high_wrist = 15;
    stats_weight.low_wrist = 5;
    stats_weight.pronation = 50;
    stats_weight.rise = 30;
    stats_weight.sidepress = 5;
    stats_weight.supination = 5;
    stats_weight.triceps = 5;
    return stats_weight;
}

StatsWeight build_lowhand_toproll()
{
    StatsWeight stats_weight;
    stats_weight.backpress = 25;
    stats_weight.biceps = 5;
    stats_weight.fingers = 15;
    stats_weight.high_wrist = 10;
    stats_weight.low_wrist = 20;
    stats_weight.pronation = 35;
    stats_weight.rise = 5;
    stats_weight.sidepress = 10;
    stats_weight.supination = 5;
    stats_weight.triceps = 5;
    return stats_weight;
}

StatsWeight build_post_toproll()
{
    StatsWeight stats_weight;
    stats_weight.backpress = 25;
    stats_weight.biceps = 5;
    stats_weight.fingers = 10;
    stats_weight.high_wrist = 20;
    stats_weight.low_wrist = 5;
    stats_weight.pronation = 30;
    stats_weight.rise = 25;
    stats_weight.sidepress = 10;
    stats_weight.supination = 5;
    stats_weight.triceps = 5;
    return stats_weight;
}

StatsWeight build_flop()
{
    StatsWeight stats_weight;
    stats_weight.backpress = 5;
    stats_weight.biceps = 5;
    stats_weight.fingers = 5;
    stats_weight.high_wrist = 5;
    stats_weight.low_wrist = 5;
    stats_weight.pronation = 5;
    stats_weight.rise = 5;
    stats_weight.sidepress = 30;
    stats_weight.supination = 5;
    stats_weight.triceps = 40;
    return stats_weight;
}