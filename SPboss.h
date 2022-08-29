#pragma once
#include "JEFE.h"
#include "vector"
#include "Composite.h"
class SPboss :public Composite<JEFE> {
protected:
	std::vector <std::shared_ptr<JEFE>> listaB;
	void add(sf::RenderWindow*, int);
	void deletes();
	void show(Base*);
	void ataque(Base*&, std::shared_ptr<JEFE>, int);
	std::vector <std::shared_ptr<JEFE>> getvec();
	int retroceso;
public:
	SPboss() {};
	void execute_attack(Base*&, std::shared_ptr<JEFE>, int) override;
	void add_object(sf::RenderWindow*, int) override;
	void deletes_object() override;
	void show_object(Base*) override;
	void set_retroceso(int) override;
	std::vector<std::shared_ptr<JEFE>> return_vector() override;
};