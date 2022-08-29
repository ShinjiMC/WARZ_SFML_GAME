#include "SPdisparar.h"
#include "iostream"
SPdisparar::SPdisparar() {}
void SPdisparar::add(sf::RenderWindow* ventana, Base* jugador) {
	std::shared_ptr<disparar> plot = std::make_shared<disparar>();
	plot->getSprite()->setPosition(jugador->getActorS()->getPosition().x + 30, jugador->getActorS()->getPosition().y + 40);
	plot->set_frame(jugador->getFrame()->y);
	plot->set_dir(plot->operator()(jugador));
	listaB.push_back(plot);
}
void SPdisparar::show(Base* jugador) {
	for (int i = 0; i < listaB.size(); i++) {
		int dir = listaB[i]->getdir();
		if (dir == 0) {
			listaB[i]->getSprite()->move({ 3,0 });
		}
		if (dir == 1) {
			listaB[i]->getSprite()->move({ 0,-3 });
		}
		if (dir == 2) {
			listaB[i]->getSprite()->move({ -3,0 });
		}
		if (dir == 3) {
			listaB[i]->getSprite()->move({ 0,3 });
		}
	}
}
void SPdisparar::deletes() {
	for (int j = 0; j < listaB.size(); j++) {
		if (listaB[j]->getVidas() <= 0) {
			listaB.erase(listaB.begin() + j);
		}
		else if (listaB[j]->relojs() > 5) {
			listaB.erase(listaB.begin() + j);
		}
	}
}
std::vector <std::shared_ptr<disparar>> SPdisparar::getvec() {
	return listaB;
}