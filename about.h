#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class about {
private:
	sf::RenderWindow* ventanaX;
	int fps;
	sf::Texture* fondo = new sf::Texture;
	sf::Sprite* screen = new sf::Sprite;
	sf::Event* eventoX;
	bool gameover;
	sf::Font* fuente;
	sf::Text* Palabra[19];
public:
	about(sf::Vector2i dimension, std::string titulo);
	~about() {}
	sf::RenderWindow* getventana() { return this->ventanaX; }
	void gameloop();
	void dibujar();
	void procesar_eventos();
};