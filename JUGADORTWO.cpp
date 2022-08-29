#include "JUGADORTWO.h"
JUGADORTWO::JUGADORTWO(){
	IniciarlizarAtributos();
	setImage();
	sf::Vector2i* inicio = new sf::Vector2i(0, 0);
	setSprites(8, 4);
	setFRAMEAll(inicio);
}
void JUGADORTWO::colisionMapa() {
	sf::FloatRect playerBounds = this->ActorS->getGlobalBounds();
	if (playerBounds.left + playerBounds.width >= 1760 && playerBounds.top <= 160) {
		if (playerBounds.left <= 1760) {
			this->ActorS->setPosition(1760 - playerBounds.width, playerBounds.top);
		}
		else {
			this->ActorS->setPosition(playerBounds.left, 160);
		}
	}
	if (playerBounds.left <= 160 && playerBounds.top <= 160) {
		if (playerBounds.top >= 160) {
			this->ActorS->setPosition(160, playerBounds.top);
		}
		else {
			this->ActorS->setPosition(playerBounds.left, 160);
		}
	}
	if (playerBounds.left <= 160 && playerBounds.top >= 920) {
		if (playerBounds.left <= 160) {
			this->ActorS->setPosition(160, playerBounds.top);
		}
		else {
			this->ActorS->setPosition(playerBounds.left, 920);
		}
	}
	if (playerBounds.left + playerBounds.width >= 1760 && playerBounds.top >= 920) {
		if (playerBounds.left <= 1760) {
			this->ActorS->setPosition(1760 - playerBounds.width, playerBounds.top);
		}
		else {
			this->ActorS->setPosition(playerBounds.left, 920);
		}
	}
}
void JUGADORTWO::WindowBoundsColision(const sf::RenderTarget* target) {
	sf::FloatRect playerBounds = this->ActorS->getGlobalBounds();
	if (playerBounds.left <= 0.f) {
		this->ActorS->setPosition(0.f, playerBounds.top);
	}
	else if (playerBounds.left + playerBounds.width >= target->getSize().x) {
		this->ActorS->setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	}
	if (playerBounds.top <= 0.f) {
		this->ActorS->setPosition(playerBounds.left, 0.f);
	}
	else if (playerBounds.top + playerBounds.height >= target->getSize().y) {
		this->ActorS->setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
	}
}
void JUGADORTWO::setActorT() {
	sf::Texture* textu = new sf::Texture;
	textu->loadFromFile("resources\\Character3.png");
	ActorT = textu;
}

void JUGADORTWO::setActorS(){
	sf::Sprite* spr = new sf::Sprite;
	spr->setTexture(*Base::getActorT());
	ActorS = spr;
}
void JUGADORTWO::setCant_Sprites(int fila, int columna) {
	divisionspriteX = fila;
	divisionspriteY = columna;
}
void JUGADORTWO::setFrame(sf::Vector2i* frame) {
	sf::IntRect posicion(frame->x * (ActorS->getTexture()->getSize().x / divisionspriteX), frame->y * (ActorS->getTexture()->getSize().y / divisionspriteY),
	ActorS->getTexture()->getSize().x / divisionspriteX, ActorS->getTexture()->getSize().y / divisionspriteY);
	ActorS->setTextureRect(posicion);
}