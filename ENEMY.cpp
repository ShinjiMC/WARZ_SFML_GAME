#include "ENEMY.h"
ENEMY::ENEMY() {
	IniciarlizarAtributos();
	setImage();
	sf::Vector2i* inicio = new sf::Vector2i(0, 0);
	setSprites(8, 4);
	setFRAMEAll(inicio);
	updatevidas(10);
	Ataque_Enemigo(10);
}
void ENEMY::setActorT() {
	sf::Texture* textu = new sf::Texture;
	textu->loadFromFile("resources\\Character2.png");
	ActorT = textu;
}

void ENEMY::setActorS() {
	sf::Sprite* spr = new sf::Sprite;
	spr->setTexture(*Base::getActorT());
	ActorS = spr;
}

void ENEMY::setFrame(sf::Vector2i* frame) {
	sf::IntRect posicion(frame->x * (ActorS->getTexture()->getSize().x / divisionspriteX), frame->y * (ActorS->getTexture()->getSize().y / divisionspriteY),
		ActorS->getTexture()->getSize().x / divisionspriteX, ActorS->getTexture()->getSize().y / divisionspriteY);
	ActorS->setTextureRect(posicion);
}
void ENEMY::setCant_Sprites(int fila, int columna) {
	divisionspriteX = fila;
	divisionspriteY = columna;
}
void ENEMY::setVidas(int a) {
	vidas = a;
}
void ENEMY::setdano(int dang) {
	dano = dang;
}

template<typename T>
bool MayoR(T p, T P) {
	return p > P;
}
template<typename T>
bool MenoR(T p, T P) {
	return P > p;
}

void SeguimientoY(sf::Vector2f& pos, sf::Vector2f& posP, sf::Vector2f& newpo, int val, sf::Vector2i*& frame_actual_Enemy, int divisionspriteEnemyX, int divisionspriteEnemyY) {
	bool (*Compare[2])(float, float) = { MayoR <float>,MenoR <float> };
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

void SeguimientoX(sf::Vector2f& pos, sf::Vector2f& posP, sf::Vector2f& newpo, int val, sf::Vector2i*& frame_actual_Enemy, int divisionspriteEnemyX, int divisionspriteEnemyY) {
	bool (*Compare[2])(float, float) = { MayoR <float>,MenoR <float> };
	if (Compare[0](pos.x, posP.x)) {
		newpo.x = pos.x - val;
		frame_actual_Enemy->y = 1;
		SeguimientoY(pos, posP, newpo, val, frame_actual_Enemy, divisionspriteEnemyX, divisionspriteEnemyY);
	}
	else if (Compare[1](pos.x, posP.x)) {
		newpo.x = pos.x + val;
		frame_actual_Enemy->y = 2;
		SeguimientoY(pos, posP, newpo, val, frame_actual_Enemy, divisionspriteEnemyX, divisionspriteEnemyY);
	}
	else {
		newpo.x = pos.x;
		frame_actual_Enemy->y = 0;
		SeguimientoY(pos, posP, newpo, val, frame_actual_Enemy, divisionspriteEnemyX, divisionspriteEnemyY);
	}
}

void ENEMY::FollowPlayer(Base* player) {
	int val = 1 + rand() % (4 - 1);
	sf::Vector2f pos = ActorS->getPosition();
	sf::Vector2f posP = player->getActorS()->getPosition();
	sf::Vector2f newpo;
	if (pos != posP) {
		SeguimientoX(pos, posP, newpo, val, frame_actual, divisionspriteX, divisionspriteY);
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