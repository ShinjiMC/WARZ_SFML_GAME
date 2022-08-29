#include "MainMenu.h"
MainMenu::MainMenu(float width, float height) {
	m = new sf::SoundBuffer;
	m->loadFromFile("resources\\Click.wav");
	m1 = new sf::Sound;
	m1->setBuffer(*m);
	m1->setVolume(100);
	musica = new sf::Music;
	musica->openFromFile("resources\\Theme.wav");
	musica->setVolume(10);
	musica->setLoop(true);
	fondo = new sf::Texture;
	screen = new sf::Sprite;
	fondo->loadFromFile("resources\\themeI.png");
	screen->setTexture(*fondo);
	
	if (!font.loadFromFile("resources\\8-BIT WONDER.TTF")) {
		std::cout << "No sepudo cargar la Fuente ";
	}
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("LeaderBoard");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);
	//musica->play();
	MainMenuSelected = -1;
}
MainMenu::~MainMenu(){}

void MainMenu::draw(sf::RenderWindow& window) {
	window.draw(*screen);
	for (int i = 0; i < 4; i++) {
		
		window.draw(mainMenu[i]);
	}
}
void MainMenu::MoveUp() {
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= 4) {
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}