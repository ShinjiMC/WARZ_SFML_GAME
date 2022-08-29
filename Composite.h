#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Base.h"
#include <vector>
template<typename N>
class Composite {
protected:
	virtual void add_object(sf::RenderWindow*, int) = 0;
	virtual void deletes_object() = 0;
	virtual void show_object(Base*) = 0;
	virtual void set_retroceso(int) = 0;
	virtual void execute_attack(Base*&, std::shared_ptr<N>, int) = 0;
	virtual std::vector <std::shared_ptr<N>> return_vector() = 0;
public:
	Composite() {};
	~Composite() {};
};
