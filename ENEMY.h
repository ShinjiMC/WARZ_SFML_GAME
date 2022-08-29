#pragma once
#include "BASE.h"
class ENEMY : public Base {
protected:
	void setActorT() override;
	void setActorS() override;
	void setFrame(sf::Vector2i*) override;
	void setCant_Sprites(int fila, int columna) override;
	void setVidas(int a) override;
	void setdano(int) override;
	void FollowPlayer(Base*) override;
	void setfuente() override{}
	void settxt() override{}
	void newtxt() override{}
	void setHealt() override{}
	void newhealt() override{}
	void colisionMapa() override{}
	void WindowBoundsColision(const sf::RenderTarget*) override{}
public:
	ENEMY();
	~ENEMY() {}
};

