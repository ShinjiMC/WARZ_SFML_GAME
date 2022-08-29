#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class StrategyBase {
protected:
	sf::Sprite* parent;
public:
	virtual void Start() = 0;
	virtual void Stop() = 0;
};

