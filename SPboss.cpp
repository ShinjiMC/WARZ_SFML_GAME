#include "SPboss.h"
#include "iostream"
void SPboss::execute_attack(Base*& Player, std::shared_ptr<JEFE> jefe, int val) {
	ataque(Player, jefe, val);
}
void SPboss::ataque(Base*& Player, std::shared_ptr<JEFE> jefe, int val) {
	if (Player->getActorS()->getGlobalBounds().intersects(jefe->getActorS()->getGlobalBounds())) {
		Player->updatevidas(Player->getVidas() - jefe->getdano());
		sf::Vector2f pos = jefe->getActorS()->getPosition();
		sf::Vector2f posP = Player->getActorS()->getPosition();
		if (pos.x < posP.x) {
			if (pos.y < posP.y) {
				jefe->getActorS()->setPosition(pos.x - val, pos.y - val);
			}
			else if (pos.y > posP.y) {
				jefe->getActorS()->setPosition(pos.x - val, pos.y + val);
			}
			else {
				jefe->getActorS()->setPosition(pos.x - val, pos.y);
			}

		}
		else if (pos.x > posP.x) {
			if (pos.y < posP.y) {
				jefe->getActorS()->setPosition(pos.x + val, pos.y - val);
			}
			else if (pos.y > posP.y) {
				jefe->getActorS()->setPosition(pos.x + val, pos.y + val);
			}
			else {
				jefe->getActorS()->setPosition(pos.x + val, pos.y);
			}
		}
		else {
			if (pos.y < posP.y) {
				jefe->getActorS()->setPosition(pos.x, pos.y - val);
			}
			else if (pos.y > posP.y) {
				jefe->getActorS()->setPosition(pos.x, pos.y + val);
			}
			else {
				jefe->getActorS()->setPosition(pos.x, pos.y);
			}
		}
	}
}
void SPboss::add_object(sf::RenderWindow* ventana, int danos) {
	add(ventana, danos);
}
void SPboss::add(sf::RenderWindow* ventana, int danos) {
	std::shared_ptr<JEFE> plot = std::make_shared<JEFE>();
	plot->getActorS()->setPosition(ventana->getSize().x / 2, 0);
	listaB.push_back(plot);
}

void SPboss::show(Base* jugador) {
	for (int i = 0; i < listaB.size(); i++) {
		listaB[i]->Seguimiento_ataque(jugador);
		set_retroceso(15);
		ataque(jugador, listaB[i], retroceso);
	}
}
void SPboss::show_object(Base* jugador) {
	show(jugador);
}

void SPboss::set_retroceso(int val) {
	this->retroceso = val;
}
void SPboss::deletes() {
	for (int j = 0; j < listaB.size(); j++) {
		if (listaB[j]->getVidas() <= 0) {
			listaB.erase(listaB.begin() + j);
		}
	}
}
void SPboss::deletes_object() {
	deletes();
}

std::vector <std::shared_ptr<JEFE>> SPboss::getvec() {
	return listaB;
}
std::vector<std::shared_ptr<JEFE>> SPboss::return_vector() {
	return getvec();
}