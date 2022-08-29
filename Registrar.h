#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "LeaderBoard.h"
class Registrar {
private:
	std::string text;
	sf::RenderWindow* ventanaX;
	int fps;
	sf::Texture* fondo;
	sf::Sprite* screen;
	sf::Event* eventoX;
	bool gameover;
	sf::Font* fuente;
	sf::Text* Matriz;
	sf::Text* P;
	sf::Text* AVISO;
	int puntuacion;
public:
	Registrar(int);
	void ingresarletra();
	void gameloop();
	void dibujar();
	void procesar_eventos();
};

