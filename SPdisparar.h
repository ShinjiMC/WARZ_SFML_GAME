#pragma once
#include "disparar.h"
#include "SPenemy.h"
#include "vector"
#include "Base.h" 
#include <memory>
class SPdisparar {
private:
	std::vector<std::shared_ptr<disparar>> listaB;
public:
	SPdisparar();
	void add(sf::RenderWindow*, Base*);
	void deletes();
	void show(Base*);
	std::vector <std::shared_ptr<disparar>> getvec();
};