#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
struct Records {
	std::string name;
	int puntuacion;
	Records* next;
};
typedef struct Records* lista;
class leader {
private:
	sf::RenderWindow* ventanaX;
	int fps;
	sf::Texture* fondo = new sf::Texture;
	sf::Sprite* screen = new sf::Sprite;
	sf::Event* eventoX;
	bool gameover;
	sf::Font* fuente;
	sf::Text* Matriz[10];
	lista data;
public:
	leader(sf::Vector2i dimension, std::string titulo);
	~leader() {}
	void mostrar(lista);
	sf::RenderWindow* getventana() { return ventanaX; }
	void gameloop();
	void dibujar();
	void procesar_eventos();
};
