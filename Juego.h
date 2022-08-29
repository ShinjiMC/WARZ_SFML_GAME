#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SPenemy.h"
#include "SPboss.h"
#include "SPdisparar.h"
#include "Registrar.h"
#include "JUGADORONE.h"
#include "JUGADORTWO.h"
#include "Controlador.h"
class juego {
private:
	int puntaje;
	sf::RenderWindow* ventana1;
	int fps;
	sf::Clock* relojG;
	sf::Time* tiempoG;
	sf::Clock* relojE;
	sf::Time* tiempoE;
	sf::Clock* relojB;
	sf::Time* tiempoB;
	sf::Clock* reloj;
	sf::Time* tiempo;
	sf::Texture* fondo = new sf::Texture;
	sf::Sprite* screen = new sf::Sprite;
	sf::SoundBuffer* dispaSB;
	sf::Sound* dispaS;
	JEFE* jefe;
	sf::Event* evento1;
	sf::Vector2i posicion_mouse;
	sf::Font* fuente1;
	sf::Text* txt_gameover;
	sf::Text* txt_TIEMPO;
	SPenemy* listaa;
	SPboss* listaB;
	SPdisparar* list;
	sf::Music* Mfond;
	Controlador* effect;
	ChildStrategy* full;
	HardStrategy* low;
	int contadorgen;
	bool disboss;
	int gameover;
	int spawn_enemy;
	int spawn_boss;
	int dan_enemy;
	int contadorBoss;
	bool dis;
	int dan_boss;
	Base* player1;
	Base* player2;

public:
	juego(sf::Vector2i dimension, std::string titulo);
	~juego(){}
	sf::RenderWindow* getventana() { return ventana1; }
	void generarbala();
	void generarbala2();
	void generarenemy(int);
	void generarBoss(int);
	int FastE();
	void gameloop();
	void dibujar(int);
	void procesar_eventos();
	void imprimirE(std::vector <std::shared_ptr<ENEMY>> listas);
	void imprimirB(std::vector <std::shared_ptr<JEFE>> listas);
	void imprimirBala(std::vector <std::shared_ptr<disparar>> listas);
	void procesar_mouse();
	void procesar_colisiones();
};