#pragma once
#include "Facade.h"
#include "MainMenu.h"
void ImprimirMainMenu() {
	sf::RenderWindow MENU(sf::VideoMode(1920, 1080), "Menu", sf::Style::Fullscreen);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	mainMenu.getMusic()->play();
	while (MENU.isOpen()) {
		sf::Event event;
		while (MENU.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				MENU.close();
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					mainMenu.getSound()->play();
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					mainMenu.getSound()->play();
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) {

					int x = mainMenu.MainMenuPressed();
					if (x == 0) {
						mainMenu.getMusic()->stop();
						juego* Play = new juego({ 1920,1080 }, "WARZ");
						leader* Leader = nullptr;
						about* About = nullptr;
						Facade* multiples = new Facade(Play, Leader, About);
						while (multiples->getS1()->getventana()->isOpen()) {
							sf::Event aevent;
							while (multiples->getS1()->getventana()->pollEvent(aevent)) {
								if (aevent.type == sf::Event::Closed) {
									multiples->getS1()->getventana()->close();
								}
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape) {
										multiples->getS1()->getventana()->close();
									}
								}
							}
							multiples->Operation(1);

						}
					}
					if (x == 1) {
						juego* Play =  nullptr;
						leader* Leader = new leader({ 1920,1080 }, "LEADERBOARD");
						about* About = nullptr;
						Facade* multiples = new Facade(Play, Leader, About);
						while (multiples->getS2()->getventana()->isOpen()) {
							sf::Event aevent;
							while (multiples->getS2()->getventana()->pollEvent(aevent)) {
								if (aevent.type == sf::Event::Closed) {
									multiples->getS2()->getventana()->close();
								}
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape) {
										multiples->getS2()->getventana()->close();
									}
								}
							}
							multiples->Operation(2);
							
						}
					}
					if (x == 2) {
						juego* Play=nullptr;
						leader* Leader=nullptr;
						about* About = new about({ 1920, 1080 }, "ABOUT");
						Facade* multiples = new Facade(Play, Leader, About);
						while (multiples->getS3()->getventana()->isOpen()) {
							sf::Event aevent;
							while (multiples->getS3()->getventana()->pollEvent(aevent)) {
								if (aevent.type == sf::Event::Closed) {
									multiples->getS3()->getventana()->close();
								}
								if (aevent.type == sf::Event::KeyPressed) {
									if (aevent.key.code == sf::Keyboard::Escape) {
										multiples->getS3()->getventana()->close();
									}
								}
							}
							multiples->Operation(3);
						}
					}
					if (x == 3)
						MENU.close();
					break;
				}
			}
		}
		MENU.clear();
		mainMenu.draw(MENU);
		MENU.display();
	}
}