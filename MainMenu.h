#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "iostream"
class MainMenu
{
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[4];
	sf::SoundBuffer* m;
	sf::Sound* m1;
	sf::Music* musica;
	sf::Music tecla;
	sf::Texture* fondo;
	sf::Sprite* screen;
public:
	MainMenu(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int MainMenuPressed() { return MainMenuSelected; }
	sf::Music* getMusic() { return musica; }
	sf::Sound* getSound() { return m1; }
	~MainMenu();
};

