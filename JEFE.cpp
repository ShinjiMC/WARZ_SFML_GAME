#include "JEFE.h"
JEFE::JEFE() {
	IniciarlizarAtributos();
	setImage();
	sf::Vector2i* inicio = new sf::Vector2i(0, 0);
	setSprites(9, 4);
	setFRAMEAll(inicio);
	updatevidas(50);
	Ataque_Enemigo(15);
}
void JEFE::setActorT() {
	sf::Texture* textu = new sf::Texture;
	textu->loadFromFile("resources\\Boss.png");
	ActorT = textu;
}

void JEFE::setActorS() {
	sf::Sprite* spr = new sf::Sprite;
	spr->setTexture(*Base::getActorT());
	ActorS = spr;
}

void JEFE::setFrame(sf::Vector2i* frame) {
	sf::IntRect posicion(frame->x * (ActorS->getTexture()->getSize().x / divisionspriteX), frame->y * (ActorS->getTexture()->getSize().y / divisionspriteY),
		ActorS->getTexture()->getSize().x / divisionspriteX, ActorS->getTexture()->getSize().y / divisionspriteY);
	ActorS->setTextureRect(posicion);
}
void JEFE::setCant_Sprites(int fila, int columna) {
	divisionspriteX = fila;
	divisionspriteY = columna;
}
void JEFE::setVidas(int a) {
	vidas = a;
}
void JEFE::setdano(int dang) {
	dano = dang;
}

template<typename T>
bool Mayor(T p, T P) {
	return p > P;
}
template<typename T>
bool Menor(T p, T P) {
	return P > p;
}

void seguimientoY(sf::Vector2f& pos, sf::Vector2f& posP, sf::Vector2f& newpo, int val, sf::Vector2i*& frame_actual_Enemy, int divisionspriteEnemyX, int divisionspriteEnemyY) {
	bool (*Compare[2])(float, float) = { Mayor <float>,Menor <float> };
	if (frame_actual_Enemy->y == 0) {
		if (Compare[0](pos.y, posP.y)) {
			newpo.y = pos.y - val;
			frame_actual_Enemy->y = 3;
			if (frame_actual_Enemy->x != divisionspriteEnemyX - 1) {
				frame_actual_Enemy->x = frame_actual_Enemy->x + 1;
			}
			else {
				frame_actual_Enemy->x = 0;
			}
		}
		else if (Compare[1](pos.y, posP.y)) {
			newpo.y = pos.y + val;
			frame_actual_Enemy->y = 0;
			if (frame_actual_Enemy->x != divisionspriteEnemyX - 1) {
				frame_actual_Enemy->x = frame_actual_Enemy->x + 1;
			}
			else {
				frame_actual_Enemy->x = 0;
			}
		}
		else {
			newpo.y = pos.y;
			if (frame_actual_Enemy->x != divisionspriteEnemyX - 1) {
				frame_actual_Enemy->x = frame_actual_Enemy->x + 1;
			}
			else {
				frame_actual_Enemy->x = 0;
			}
		}
	}
	else {
		if (Compare[0](pos.y, posP.y)) {
			newpo.y = pos.y - val;
			if (frame_actual_Enemy->x != divisionspriteEnemyX - 1) {
				frame_actual_Enemy->x = frame_actual_Enemy->x + 1;
			}
			else {
				frame_actual_Enemy->x = 0;
			}
		}
		else if (Compare[1](pos.y, posP.y)) {
			newpo.y = pos.y + val;
			if (frame_actual_Enemy->x != divisionspriteEnemyX - 1) {
				frame_actual_Enemy->x = frame_actual_Enemy->x + 1;
			}
			else {
				frame_actual_Enemy->x = 0;
			}
		}
		else {
			newpo.y = pos.y;
			if (frame_actual_Enemy->x != divisionspriteEnemyX - 1) {
				frame_actual_Enemy->x = frame_actual_Enemy->x + 1;
			}
			else {
				frame_actual_Enemy->x = 0;
			}
		}
	}

}

void seguimientoX(sf::Vector2f& pos, sf::Vector2f& posP, sf::Vector2f& newpo, int val, sf::Vector2i*& frame_actual_Enemy, int divisionspriteEnemyX, int divisionspriteEnemyY) {
	bool (*Compare[2])(float, float) = { Mayor <float>,Menor <float> };
	if (Compare[0](pos.x, posP.x)) {
		newpo.x = pos.x - val;
		frame_actual_Enemy->y = 1;
		seguimientoY(pos, posP, newpo, val, frame_actual_Enemy, divisionspriteEnemyX, divisionspriteEnemyY);
	}
	else if (Compare[1](pos.x, posP.x)) {
		newpo.x = pos.x + val;
		frame_actual_Enemy->y = 2;
		seguimientoY(pos, posP, newpo, val, frame_actual_Enemy, divisionspriteEnemyX, divisionspriteEnemyY);
	}
	else {
		newpo.x = pos.x;
		frame_actual_Enemy->y = 0;
		seguimientoY(pos, posP, newpo, val, frame_actual_Enemy, divisionspriteEnemyX, divisionspriteEnemyY);
	}
}

void JEFE::FollowPlayer(Base* player) {
	int val = 1 + rand() % (4 - 1);
	sf::Vector2f pos = ActorS->getPosition();
	sf::Vector2f posP = player->getActorS()->getPosition();
	sf::Vector2f newpo;
	if (pos != posP) {
		seguimientoX(pos, posP, newpo, val, frame_actual, divisionspriteX, divisionspriteY);
	}
	else {
		newpo.x = pos.x;
		newpo.y = pos.y;
		frame_actual->x = 0;
		frame_actual->y = 0;
	}
	ActorS->setPosition(newpo);
	setFRAMEAll(frame_actual);
}