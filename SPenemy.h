#pragma once
#include "ENEMY.h"
#include "vector"
#include "Composite.h"
class SPenemy :public Composite<ENEMY> {
protected:
	std::vector <std::shared_ptr<ENEMY>> lista;
	void add(sf::RenderWindow*, int);
	void deletes();
	void show(Base*);
	void ataque(Base*&, std::shared_ptr<ENEMY>, int);
	std::vector <std::shared_ptr<ENEMY>> getvector();
	int retroceso;
public:
	SPenemy() {};
	void execute_attack(Base*&, std::shared_ptr<ENEMY>, int) override;
	void add_object(sf::RenderWindow*, int) override;
	void deletes_object() override;
	void show_object(Base*) override;
	void set_retroceso(int) override;
	std::vector<std::shared_ptr<ENEMY>> return_vector() override;
};

