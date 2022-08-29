#pragma once
#include "StrategyBase.h"
class ChildStrategy : public StrategyBase {
public:
	ChildStrategy(sf::Sprite* a) { parent = a; }
	~ChildStrategy() {}
    void Start() override {
        parent->setColor({ 123, 129, 206 });
    }
    void Stop() override {}
};

