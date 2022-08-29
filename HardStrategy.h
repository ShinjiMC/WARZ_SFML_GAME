#pragma once
#include "StrategyBase.h"
class HardStrategy : public StrategyBase {
public:
    HardStrategy(sf::Sprite* a) { parent = a; }
    ~HardStrategy() {}
    void Start() override {
        parent->setColor({ 226, 92, 105 });
    }
    void Stop() override {}
};

