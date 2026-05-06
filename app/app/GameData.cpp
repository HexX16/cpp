#include <map>
#include <vector>
#include <string>
#include "GameData.h"

std::map<std::string, int> get_default_params()
{
    std::map<std::string, int> power_params = {
        {"backpress", 0},
        {"biceps", 0},
        {"fingers", 0},
        {"high_wrist", 0},
        {"low_wrist", 0},
        {"pronation", 0},
        {"rise", 0},
        {"sidepress", 0},
        {"supination", 0},
        {"triceps", 0}
    };
    return power_params;
}

const std::vector<std::string> get_techs()
{
    const std::vector<std::string> techs = {
        "hook",
        "kingsmove",
        "lowhand toproll",
        "post toproll",
        "flop press"
    };
    return techs;
}

float matchup[TECH_COUNT][TECH_COUNT] = {
    //               HOOK    KM     LHTR   PTR    FLOP

    /* HOOK */     { 1.00f, 0.85f, 0.85f, 1.10f, 1.15f },

    /* KINGSMOVE */ { 1.15f, 1.00f, 1.10f, 0.90f, 0.85f },

    /* LHTR */     { 1.20f, 0.85f, 1.00f, 0.90f, 0.85f },

    /* PTR */      { 0.90f, 1.10f, 1.10f, 1.00f, 0.85f },

    /* FLOP */     { 0.85f, 1.15f, 1.15f, 1.15f, 1.00f }
};

void init_weights(Weights (& weights)[TECH_COUNT][TECH_COUNT]) {
    //HOOK vs
    weights[HOOK][HOOK] = {
        0.8f,
        1.3f,
        0.8f,
        0.8f,
        1.0f,
        1.15f,
        0.9f,
        1.4f,
        0.9f,
        1.0f
    };
    weights[HOOK][KINGSMOVE] = {
        0.8f,
        1.0f,
        1.2f,
        1.0f,
        1.4f,
        0.8f,
        0.9f,
        1.2f,
        1.1f,
        1.0f
    };
    weights[HOOK][LHTR] = {
        0.8f,
        1.0f,
        1.3f,
        0.9f,
        1.4f,
        0.8f,
        0.8f,
        1.2f,
        1.1f,
        0.9f
    };
    weights[HOOK][PTR] = {
        0.8f,
        1.0f,
        1.3f,
        0.9f,
        1.4f,
        0.8f,
        0.8f,
        1.2f,
        1.1f,
        0.9f
    };
    weights[HOOK][FLOP] = {
        0.8f,
        0.9f,
        0.8f,
        1.0f,
        1.4f,
        0.8f,
        0.8f,
        1.4f,
        1.4f,
        0.9f
    };



    //KINGSMOVE vs
    weights[KINGSMOVE][HOOK] = {
       1.2f,
       1.1f,
       0.8f,
       1.2f,
       1.0f,
       1.4f,
       1.0f,
       1.0f,
       0.8f,
       0.8f
    };
    weights[KINGSMOVE][KINGSMOVE] = {
       1.0f,
       0.9f,
       0.8f,
       1.3f,
       1.0f,
       1.3f,
       1.4f,
       1.0f,
       0.8f,
       0.8f
    };
    weights[KINGSMOVE][LHTR] = {
       0.8f,
       0.9f,
       0.8f,
       1.2f,
       1.2f,
       1.4f,
       1.0f,
       1.0f,
       0.8f,
       0.8f
    };
    weights[KINGSMOVE][PTR] = {
       0.9f,
       0.9f,
       0.8f,
       1.3f,
       1.0f,
       1.3f,
       1.4f,
       1.0f,
       0.8f,
       0.8f
    };
    weights[KINGSMOVE][FLOP] = {
       1.4f,
       1.1f,
       0.8f,
       0.8f,
       1.0f,
       1.0f,
       1.2f,
       1.2f,
       0.8f,
       0.8f
    };



    //LHTP vs

    /*  {"backpress", 0},
        {"biceps", 0},
        {"fingers", 0},
        {"high_wrist", 0},
        {"low_wrist", 0},
        {"pronation", 0},
        {"rise", 0},
        {"sidepress", 0},
        {"supination", 0},
        {"triceps", 0}*/
}