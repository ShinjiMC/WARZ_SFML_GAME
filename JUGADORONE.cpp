#include "JUGADORONE.h"
void JUGADORONE::setCant_Sprites(int fila, int columna) {
	divisionspriteX = fila;
	divisionspriteY = columna;
}
JUGADORONE::JUGADORONE() {
	IniciarlizarAtributos();
	setImage();
	sf::Vector2i* inicio = new sf::Vector2i(0, 0);
	setSprites(8, 4);
	setFRAMEAll(inicio);
	updatevidas(100);
}
void JUGADORONE::setfuente() {
	fuente1->loadFromFile("resources\\8-BIT WONDER.TTF");
}
void JUGADORONE::settxt() {
	txt_vidas->setFont(*fuente1);
	txt_vidas->setPosition(10, 10);
	txt_vidas->setFillColor(sf::Color::Black);
}
void JUGADORONE::newtxt() {
	txt_vidas->setString("PLAYER ONE " + std::to_string(vidas));
}
void JUGADORONE::setHealt() {
	healthBarT->loadFromFile("resources\\verde.png");
	healthBar->setTexture(*healthBarT);
	healthBar->setPosition(400, 20);
	healthBar->setScale(1, 0.3);
}
void JUGADORONE::newhealt() {
	if (vidas <= 0)	{
		vidas = 0;
	}
	healthBar->setScale({ (float)vidas / 100, 0.1 });
}
void JUGADORONE::colisionMapa() {
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
void JUGADORONE::WindowBoundsColision(const sf::RenderTarget* target) {
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
void JUGADORONE::setActorT() {
	sf::Texture* textu = new sf::Texture;
	textu->loadFromFile("resources\\Character1.png");
	ActorT = textu;
}

void JUGADORONE::setActorS(){
	sf::Sprite* spr = new sf::Sprite;
	spr->setTexture(*Base::getActorT());
	ActorS = spr;
}

void JUGADORONE::setFrame(sf::Vector2i* frame) {
	sf::IntRect posicion(frame->x * (ActorS->getTexture()->getSize().x / divisionspriteX), frame->y * (ActorS->getTexture()->getSize().y / divisionspriteY),
	ActorS->getTexture()->getSize().x / divisionspriteX, ActorS->getTexture()->getSize().y / divisionspriteY);
	ActorS->setTextureRect(posicion);
}

void JUGADORONE::setVidas(int a) {
	vidas = a;
}
