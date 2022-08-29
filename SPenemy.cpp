#include "SPenemy.h"
#include<time.h>
void SPenemy::execute_attack(Base*& Player, std::shared_ptr<ENEMY> jefe, int val) {
	ataque(Player, jefe, val);
}
void SPenemy::ataque(Base*& Player, std::shared_ptr<ENEMY> jefe, int val) {
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
void SPenemy::add(sf::RenderWindow* ventana, int danos) {
	std::shared_ptr<ENEMY> plot = std::make_shared<ENEMY>();
	srand(time(NULL));
	int n = 1 + rand() % (4 - 1);
	int n2 = 1 + rand() % (3 - 1);
	if (n == 3 && n2 == 3) {
		plot->getActorS()->setPosition(1920 / n - 1, 1080 / n2 + 1);
	}
	else {
		plot->getActorS()->setPosition(1920 / n, 1080 / n2);
	}
	lista.push_back(plot);
}
void SPenemy::add_object(sf::RenderWindow* ventana, int danos) {
	add(ventana, danos);
}
void SPenemy::set_retroceso(int val) {
	this->retroceso = val;
}
void SPenemy::show(Base* jugador) {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->Seguimiento_ataque(jugador);
		set_retroceso(15);
		ataque(jugador, lista[i], retroceso);
	}
}
void SPenemy::show_object(Base* jugador) {
	show(jugador);
}
void SPenemy::deletes() {
	for (int j = 0; j < lista.size(); j++) {
		if (lista[j]->getVidas() <= 0) {
			lista.erase(lista.begin() + j);
		}
	}
}
void SPenemy::deletes_object() {
	deletes();
}
std::vector <std::shared_ptr<ENEMY>> SPenemy::getvector() {
	return lista;
}
std::vector<std::shared_ptr<ENEMY>> SPenemy::return_vector() {
	return getvector();
}