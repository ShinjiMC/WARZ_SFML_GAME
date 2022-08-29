#include "disparar.h"
template<int val>
struct setframe {
	enum {
		value = setframe<val>::value
	};
};;
template<>
struct setframe<2> {
	enum {
		value = 0
	};
};
template<>
struct setframe<0> {
	enum {
		value = 90
	};
};
template<>
struct setframe<1> {
	enum {
		value = 180
	};
};
template<>
struct setframe<3> {
	enum {
		value = 270
	};
};
disparar::disparar() {
	DisparoT = new sf::Texture;
	DisparoS = new sf::Sprite;
	DisparoT->loadFromFile("resources\\bala.png");
	DisparoS->setTexture(*DisparoT);
	DisparoS->setScale({ 0.05,0.05 });
	dan = 10;
	dir = 0;
	vidas = 1;
	reloj = new sf::Clock;
	tiempo = new sf::Time;
}

void disparar::set_frame(int val) {
	if (val == 0) {
		DisparoS->setRotation(setframe<0>::value);
	}
	else if (val == 3) {
		DisparoS->setRotation(setframe<3>::value);
	}
	else if (val == 2) {
		DisparoS->setRotation(setframe<2>::value);
	}
	else if (val == 1) {
		DisparoS->setRotation(setframe<1>::value);
	}
}
void disparar::set_pos(sf::Vector2f pos) {
	DisparoS->setPosition(pos);
}
int disparar::operator()(Base* playerOne) {
	int dir = 0;
	sf::Vector2i* posP = playerOne->getFrame();
	if (posP->y == 0) {
		dir = 3;
	}
	else if (posP->y == 1) {
		dir = 2;
	}
	else if (posP->y == 2) {
		dir = 0;
	}
	else if (posP->y == 3) {
		dir = 1;
	}
	return dir;
}
void disparar::set_dir(int vol) { dir = vol; }
sf::Sprite* disparar::getSprite() {
	return DisparoS;
}