#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Base {
protected:
	sf::Texture* ActorT;
	sf::Sprite* ActorS;
	int divisionspriteX;
	int divisionspriteY;
	sf::Vector2i* frame_actual;
	int vidas;
	sf::Texture* healthBarT;
	sf::Sprite* healthBar;
	sf::Font* fuente1;
	sf::Text* txt_vidas;
	int dano;
	virtual void setActorT() = 0;
	virtual void setActorS() = 0;
	virtual void setFrame(sf::Vector2i*)=0;
	virtual void setVidas(int){}
	virtual void setCant_Sprites(int fila, int columna)=0;
	virtual void colisionMapa() = 0;
	virtual void WindowBoundsColision(const sf::RenderTarget* target) = 0;
	virtual void setfuente() = 0;
	virtual void settxt() = 0;
	virtual void newtxt() = 0;
	virtual void setHealt() = 0;
	virtual void newhealt() = 0;
	virtual void setdano(int) = 0;
	virtual void FollowPlayer(Base*) = 0;
public:
	void IniciarlizarAtributos() {
		ActorT = new sf::Texture;
		ActorS = new sf::Sprite;
		frame_actual = new sf::Vector2i;
		healthBarT = new sf::Texture;
		healthBar = new sf::Sprite;
		fuente1 = new sf::Font;
		txt_vidas= new sf::Text;
	}
	void setImage() {
		setActorT();
		setActorS();
	}
	void setFRAMEAll(sf::Vector2i* Position) {
		setFrame(Position);
	}
	void setSprites(int filas, int columnas) {
		setCant_Sprites(filas, columnas);
	}
	void Colision(sf::RenderTarget* target) {
		colisionMapa();
		WindowBoundsColision(target);
	}
	void setURVida() {
		setfuente();
		settxt();
		setHealt();
	}
	void updatetextovida() {
		newtxt();
		newhealt();
	}
	void updatevidas(int a) {
		setVidas(a);
	}
	void Ataque_Enemigo(int a) {
		setdano(a);
	}
	void Seguimiento_ataque(Base* player) {
		FollowPlayer(player);
	}
	sf::Texture* getActorT() { return ActorT; }
	sf::Sprite* getActorS() { return ActorS; }
	int getX() { return divisionspriteX; }
	int getY() { return divisionspriteY; }
	sf::Vector2i* getFrame() { return frame_actual; }
	int getVidas() { return vidas; }
	sf::Font* getfuente() { return fuente1; }
	sf::Text* gettxt() { return txt_vidas; }
	sf::Sprite getSpriteHealthBar() { return *healthBar; }
	int getdano() { return dano; }
};
