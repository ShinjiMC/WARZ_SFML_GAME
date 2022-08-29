#include "about.h"
about::about(sf::Vector2i dimension, std::string titulo) {
	fps = 60;
	ventanaX = new sf::RenderWindow(sf::VideoMode(dimension.x, dimension.y), titulo, sf::Style::Fullscreen);
	ventanaX->setFramerateLimit(fps);
	fondo->loadFromFile("resources\\about.jpg");
	screen->setTexture(*fondo);
	screen->setScale((float)(ventanaX->getSize().x) / fondo->getSize().x, (float)ventanaX->getSize().y / fondo->getSize().y);
	eventoX = new sf::Event;
	gameover = true;
	fuente = new sf::Font();
	fuente->loadFromFile("resources\\abc.TTF");
	Palabra[0]= new sf::Text();
	Palabra[0]->setFont(*fuente);
	Palabra[0]->setString("Creadores");
	Palabra[0]->setPosition(350, 220);
	Palabra[1] = new sf::Text();
	Palabra[1]->setFont(*fuente);
	Palabra[1]->setString("* MALDONADO CASTILLA Braulio");
	Palabra[1]->setPosition(100, 300);
	Palabra[2] = new sf::Text();
	Palabra[2]->setFont(*fuente);
	Palabra[2]->setString("* MALDONADO CASTILLA Braulio");
	Palabra[2]->setPosition(100, 360);
	Palabra[3] = new sf::Text();
	Palabra[3]->setFont(*fuente);
	Palabra[3]->setString("* GUTIERREZ ZEBALLOS Jaime");
	Palabra[3]->setPosition(100, 420);
	Palabra[4] = new sf::Text();
	Palabra[4]->setFont(*fuente);
	Palabra[4]->setString("* NIZAMA CESPEDES Juan");
	Palabra[4]->setPosition(100, 480);
	Palabra[5] = new sf::Text();
	Palabra[5]->setFont(*fuente);
	Palabra[5]->setString("* QUILCA HUAMANI Bryan");
	Palabra[5]->setPosition(100, 540);
	Palabra[6] = new sf::Text();
	Palabra[6]->setFont(*fuente);
	Palabra[6]->setString("* QUISPE ROJAS Javier");
	Palabra[6]->setPosition(100, 600);
	Palabra[7] = new sf::Text();
	Palabra[7]->setFont(*fuente);
	Palabra[7]->setString("Modo de Uso");
	Palabra[7]->setPosition(1250, 220);
	Palabra[8] = new sf::Text();
	Palabra[8]->setFont(*fuente);
	Palabra[8]->setString(" W -> Arriba");
	Palabra[8]->setPosition(1200, 300);
	Palabra[9] = new sf::Text();
	Palabra[9]->setFont(*fuente);
	Palabra[9]->setString(" S -> Abajo");
	Palabra[9]->setPosition(1200, 360);
	Palabra[10] = new sf::Text();
	Palabra[10]->setFont(*fuente);
	Palabra[10]->setString(" D -> Derecha");
	Palabra[10]->setPosition(1200, 420);
	Palabra[11] = new sf::Text();
	Palabra[11]->setFont(*fuente);
	Palabra[11]->setString(" A -> Izquierda");
	Palabra[11]->setPosition(1200, 480);
	Palabra[12] = new sf::Text();
	Palabra[12]->setFont(*fuente);
	Palabra[12]->setString("Modo de Uso Player 2");
	Palabra[12]->setPosition(1250, 600);
	Palabra[13] = new sf::Text();
	Palabra[13]->setFont(*fuente);
	Palabra[13]->setString(" ^ = Arriba");
	Palabra[13]->setPosition(1200, 680);
	Palabra[14] = new sf::Text();
	Palabra[14]->setFont(*fuente);
	Palabra[14]->setString(" v = Abajo");
	Palabra[14]->setPosition(1200, 760);
	Palabra[15] = new sf::Text();
	Palabra[15]->setFont(*fuente);
	Palabra[15]->setString(" -> = Derecha");
	Palabra[15]->setPosition(1200, 820);
	Palabra[16] = new sf::Text();
	Palabra[16]->setFont(*fuente);
	Palabra[16]->setString(" <- = Izquierda");
	Palabra[16]->setPosition(1200, 900);
	Palabra[17] = new sf::Text();
	Palabra[17]->setFont(*fuente);
	Palabra[17]->setString(" Espacio = Disparar");
	Palabra[17]->setPosition(1200, 540);
	Palabra[18] = new sf::Text();
	Palabra[18]->setFont(*fuente);
	Palabra[18]->setString(" Enter = Disparar");
	Palabra[18]->setPosition(1200, 980);
	gameloop();
}
void about::gameloop() {

	while (gameover == true) {
		procesar_eventos();
		dibujar();
		if (eventoX->type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				break;

			}
		}
	}
	ventanaX->close();
}
void about::dibujar() {
	ventanaX->clear();
	ventanaX->draw(*screen);
	for (int i = 0; i < 19; i++) {
		ventanaX->draw(*Palabra[i]);
	}
	ventanaX->display();
}
void about::procesar_eventos() {

	while (ventanaX->pollEvent(*eventoX)) {
		
		if (eventoX->type == sf::Event::Closed) {
			ventanaX->close();
			exit(1);
			break;
		}
		break;
	}
}