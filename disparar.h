#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "BASE.h"
class disparar {
protected:
	sf::Texture* DisparoT;
	sf::Sprite* DisparoS;
	sf::Time* tiempo;
	sf::Clock* reloj;
	int dir;
	int dan;
	int vidas;
public:
	disparar();
	void set_frame(int);
	void set_dir(int);
	int getdir() { return dir; }
	void set_pos(sf::Vector2f);
	int operator()(Base* player);
	sf::Sprite* getSprite();
	int getdan() { return dan; }
	int getVidas() { return vidas; }
	void setVidas(int a) { vidas = a; }
	int relojs() { *tiempo = reloj->getElapsedTime(); return tiempo->asSeconds(); }
};

