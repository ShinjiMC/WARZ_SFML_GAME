#include "Juego.h"
juego::juego(sf::Vector2i dimension, std::string titulo) {
	fps = 120;
	ventana1 = new sf::RenderWindow(sf::VideoMode(dimension.x,dimension.y), titulo, sf::Style::Fullscreen);
	ventana1->setFramerateLimit(fps);
	ventana1->setMouseCursorVisible(false);
	fondo->loadFromFile("resources\\fondo.png");
	screen->setTexture(*fondo);
	screen->setScale((float)(ventana1->getSize().x)/fondo->getSize().x, (float) ventana1->getSize().y/fondo->getSize().y);
	evento1 = new sf::Event;
	relojE = new sf::Clock;
	tiempoE = new sf::Time;
	relojB = new sf::Clock;
	tiempoB = new sf::Time;
	reloj = new sf::Clock;
	tiempo = new sf::Time;
	gameover = 1;
	listaa = new SPenemy();
	list = new SPdisparar();
	listaB = new SPboss();
	relojG = new sf::Clock;
	tiempoG = new sf::Time;
	dispaSB = new sf::SoundBuffer;
	dispaS = new sf::Sound;
	txt_TIEMPO = new sf::Text;
	Mfond = new sf::Music;
	effect = new Controlador();
	full = new ChildStrategy(screen);
	low = new HardStrategy(screen);
	dis = false;
	dispaSB->loadFromFile("resources\\shot.wav");
	dispaS->setBuffer(*dispaSB);
	dispaS->setVolume(20);
	spawn_enemy=5;
	spawn_boss=30;
	dan_enemy = 5;
	dan_boss = 10;
	contadorgen = 5;
	contadorBoss = 1;
	fuente1 = new sf::Font();
	fuente1->loadFromFile("resources\\8-BIT WONDER.TTF");
	txt_gameover = new sf::Text();
	txt_gameover->setFont(*fuente1);
	txt_gameover->setPosition((dimension.x / 2), (dimension.y / 2));
	txt_gameover->setFillColor(sf::Color::Black);
	txt_gameover->setString("GAME OVER");
	listaa->add_object(ventana1,dan_enemy);
	txt_TIEMPO->setFont(*fuente1);
	sf::FloatRect bounds=txt_TIEMPO->getLocalBounds();
	txt_TIEMPO->setPosition(1800 - bounds.width, 20);
	txt_TIEMPO->setFillColor(sf::Color::Black);
	puntaje = 0;
	Mfond->openFromFile("resources\\FondoJuego.wav");
	Mfond->setVolume(30);
	Mfond->setLoop(true);
	Mfond->play();
	player1 = new JUGADORONE();
	player2 = new JUGADORTWO();
	player1->setURVida();
	player1->getActorS()->setPosition((dimension.x / 2), (dimension.y / 2));
	player2->getActorS()->setPosition((dimension.x / 2) + 90, (dimension.y / 2) + 90);
	gameloop();
}
void juego::generarenemy(int a) {
	*tiempoE = relojE->getElapsedTime();
	if (tiempoE->asSeconds() > a) {
		if ((int)listaa->return_vector().size() < 10) {
			for (int i = 0; i < contadorgen; i++) {
				listaa->add_object(ventana1, dan_enemy);
			}
			contadorgen++;
		}
		relojE->restart();
	}
}

void juego::generarBoss(int b) {
	*tiempoB = relojB->getElapsedTime();
	if (tiempoB->asSeconds() > b) {
		for (int i = 0; i < contadorBoss; i++) {
			listaB->add_object(ventana1, dan_boss);
		}
		relojB->restart();
	}
}

void juego::generarbala() {
	if (dis == true) {
		list->add(ventana1, player1);
		dis = false;
	}
}
void juego::generarbala2() {
	if (disboss == true) {
		list->add(ventana1, player2);
		disboss = false;
	}
}
void juego::gameloop() {
	int relojs = 0;
	while (gameover > 0) {
		std::srand(time(NULL));
		procesar_colisiones();
		procesar_eventos();
		if (gameover > 1) {
			*tiempoG = relojG->getElapsedTime();
			puntaje = puntaje + (int)tiempoG->asSeconds();
			txt_gameover->setString("GAME OVER " + std::to_string(puntaje));
			ventana1->draw(*txt_gameover);
			Mfond->stop();
			Registrar* men = new Registrar(puntaje);
			men->gameloop();
			break;
		}
		else {
			dibujar(relojs);
		}
	}
	ventana1->close();
}

void juego::imprimirB(std::vector <std::shared_ptr<JEFE>> listas) {
	for (int i = 0; i < (int)listas.size(); i++) {
		ventana1->draw(*listas[i]->getActorS());
	}
}

void juego::imprimirE(std::vector <std::shared_ptr<ENEMY>> listas) {
	for (int i = 0; i < (int)listas.size(); i++) {
		ventana1->draw(*listas[i]->getActorS());
	}
}

void juego::imprimirBala(std::vector <std::shared_ptr<disparar>> listas) {
	for (int i = 0; i < (int)listas.size(); i++) {
		ventana1->draw(*listas[i]->getSprite());
	}
}
int juego::FastE() {
	*tiempo = reloj->getElapsedTime();
	if (tiempo->asSeconds() > 120) {
		reloj->restart();
		return 1;
	}
	else { return 0; }
}
void aumentdan(int& a, int& b, int c) {
	a = a + c;
	b = b + c;
}
int reductorE(int a,int c) {
	if (a - c != 2) {
		return a - c;
	}
	else {
		return a;
	}
}
int reductorB(int a, int c) {
	if (a - c != 5) {
		return a - c;
	}
	else {
		return a;
	}
}
void showB(SPdisparar* jugador, SPboss* lista,int& puntaje) {
	for (int i = 0; i < (int)jugador->getvec().size(); i++) {
		//listaB[i]->atac(jugador);
		for (int j = 0; j < (int)lista->return_vector().size(); j++) {
			if (jugador->getvec()[i]->getSprite()->getGlobalBounds().intersects(lista->return_vector()[j]->getActorS()->getGlobalBounds())) {
				lista->return_vector()[j]->updatevidas(lista->return_vector()[j]->getVidas() - jugador->getvec()[i]->getdan());
				if (lista->return_vector()[j]->getVidas() <= 0) {
					puntaje = puntaje + 100;
				}
				jugador->getvec()[i]->setVidas(jugador->getvec()[i]->getVidas() - 1);
			}
		}
	}
}
void show(SPdisparar* jugador, SPenemy* lista, int& puntaje) {
	for (int i = 0; i < (int)jugador->getvec().size(); i++) {
		//listaB[i]->atac(jugador);
		for (int j = 0; j < (int)lista->return_vector().size(); j++) {
			if (jugador->getvec()[i]->getSprite()->getGlobalBounds().intersects(lista->return_vector()[j]->getActorS()->getGlobalBounds())) {
				lista->return_vector()[j]->updatevidas(lista->return_vector()[j]->getVidas() - jugador->getvec()[i]->getdan());
				if (lista->return_vector()[j]->getVidas() <= 0) {
					puntaje = puntaje + 10;
				}
				jugador->getvec()[i]->setVidas(jugador->getvec()[i]->getVidas() - 1);
			}
		}
	}
}
void juego::dibujar(int relojs) {
	ventana1->clear();
	int time = tiempo->asSeconds();
	std::string tiemd = std::to_string(time);
	txt_TIEMPO->setString(tiemd);
	//jugador->set_healthbar(jugador->getvidas());
	//jugador->setText(jugador->getvidas());
	showB(list, listaB, puntaje);
	show(list, listaa,puntaje);
	ventana1->draw(*screen);	
	//jugador->colisionMapa();
	//jugador->WindowBoundsColision(ventana1);
	player1->updatetextovida();
	player1->Colision(ventana1);
	//jugador2->colisionMapa();
	//jugador2->WindowBoundsColision(ventana1);
	player2->Colision(ventana1);
	imprimirB(listaB->return_vector());
	imprimirE(listaa->return_vector());
	imprimirBala(list->getvec());
	listaa->show_object(player1);
	listaB->show_object(player1);
	list->show(player1);
	listaa->deletes_object();
	listaB->deletes_object();
	list->deletes();
	aumentdan(dan_enemy, dan_boss, FastE());
	spawn_enemy = reductorE(spawn_enemy, FastE());
	spawn_boss = reductorB(spawn_boss, FastE());
	generarenemy(spawn_enemy);
	generarBoss(spawn_boss);
	generarbala();
	generarbala2();
	ventana1->draw(*txt_TIEMPO);
	//ventana1->draw(*jugador->getTEXT());
	//ventana1->draw(*jugador->getSprite());
	ventana1->draw(*player1->gettxt());
	ventana1->draw(*player1->getActorS());
	ventana1->draw(player1->getSpriteHealthBar());
	//ventana1->draw(jugador2->getSprite2());
	ventana1->draw(*player2->getActorS());
	//ventana1->draw(jugador->getSpriteHealthBar());
	ventana1->display();
	if (evento1->type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			dis = true;
			dispaS->play();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			disboss = true;
			dispaS->play();
		}
	}
	if (1 > player1->getVidas()) {
		effect->StopInterface();
		gameover ++;
	}
	else if (50 > player1->getVidas()) {
		effect->StopInterface();
		effect->SetStrategy(low);
		effect->StartInterface();
	}
	else {
		effect->SetStrategy(full);
		effect->StartInterface();
	}
}
void juego::procesar_eventos() {
	int velocidad = 20;
	while (ventana1->pollEvent(*evento1)) {
		if (evento1->type == sf::Event::Closed) {
			ventana1->close();
			exit(1);
			break;
		}
		
		else if (evento1->type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				player1->getFrame()->y = 0;
				if (player1->getFrame()->x != player1->getX() - 1) {
					player1->getFrame()->x++;
				}
				else {
					player1->getFrame()->x = 0;
				}
				player1->setFRAMEAll(player1->getFrame());
				player1->getActorS()->setPosition(player1->getActorS()->getPosition().x, player1->getActorS()->getPosition().y + velocidad);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player1->getFrame()->y = 1;
				if (player1->getFrame()->x != player1->getX() - 1) {
					player1->getFrame()->x++;
				}
				else {
					player1->getFrame()->x = 0;
				}
				player1->setFRAMEAll(player1->getFrame());
				player1->getActorS()->setPosition(player1->getActorS()->getPosition().x - velocidad, player1->getActorS()->getPosition().y);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				player1->getFrame()->y = 3;
				if (player1->getFrame()->x != player1->getX() - 1) {
					player1->getFrame()->x++;
				}
				else {
					player1->getFrame()->x = 0;
				}
				player1->setFRAMEAll(player1->getFrame());
				player1->getActorS()->setPosition(player1->getActorS()->getPosition().x, player1->getActorS()->getPosition().y - velocidad);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player1->getFrame()->y = 2;
				if (player1->getFrame()->x != player1->getX() - 1) {
					player1->getFrame()->x++;
				}
				else {
					player1->getFrame()->x = 0;
				}
				player1->setFRAMEAll(player1->getFrame());
				player1->getActorS()->setPosition(player1->getActorS()->getPosition().x + velocidad, player1->getActorS()->getPosition().y);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player2->getFrame()->y = 0;
				if (player2->getFrame()->x != player2->getX() - 1) {
					player2->getFrame()->x++;
				}
				else {
					player2->getFrame()->x = 0;
				}
				player2->setFRAMEAll(player2->getFrame());
				player2->getActorS()->setPosition(player2->getActorS()->getPosition().x, player2->getActorS()->getPosition().y + velocidad);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player2->getFrame()->y = 1;
				if (player2->getFrame()->x != player2->getX() - 1) {
					player2->getFrame()->x++;
				}
				else {
					player2->getFrame()->x = 0;
				}
				player2->setFRAMEAll(player2->getFrame());
				player2->getActorS()->setPosition(player2->getActorS()->getPosition().x - velocidad, player2->getActorS()->getPosition().y);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				player2->getFrame()->y = 3;
				if (player2->getFrame()->x != player2->getX() - 1) {
					player2->getFrame()->x++;
				}
				else {
					player2->getFrame()->x = 0;
				}
				player2->setFRAMEAll(player2->getFrame());
				player2->getActorS()->setPosition(player2->getActorS()->getPosition().x, player2->getActorS()->getPosition().y - velocidad);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player2->getFrame()->y = 2;
				if (player2->getFrame()->x != player2->getX() - 1) {
					player2->getFrame()->x++;
				}
				else {
					player2->getFrame()->x = 0;
				}
				player2->setFRAMEAll(player2->getFrame());
				player2->getActorS()->setPosition(player2->getActorS()->getPosition().x + velocidad, player2->getActorS()->getPosition().y);
			}
		}
		break;
	}
}

void juego::procesar_mouse() {
	posicion_mouse = sf::Mouse::getPosition(*ventana1);
	posicion_mouse = (sf::Vector2i)ventana1->mapPixelToCoords(posicion_mouse);
}

void juego::procesar_colisiones() {
	sf::FloatRect posicion_del_mouse(sf::Vector2f(posicion_mouse), { 32,32 });

	if (player1->getActorS()->getGlobalBounds().intersects(posicion_del_mouse)) {
		player1->getActorS()->setPosition(sf::Vector2f(posicion_mouse));
	}
}