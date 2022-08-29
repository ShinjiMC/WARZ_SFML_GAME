#pragma once
#include "LeaderBoard.h"
#include <iostream>
#include <charconv>
lista crear(std::string n, int p) {
	lista nuevo = new Records();
	nuevo->name = n;
	nuevo->puntuacion = p;
	nuevo->next = NULL;
	return nuevo;
}
void insertar(lista& data, std::string n, int p) {
	if (data == NULL) {
		data = crear(n, p);
	}
	else {
		insertar(data->next, n, p);
	}
}
std::string getName(lista data, int val) {
	for (int i = 0; i < val; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		data = data->next;
	}
	return data->name;
}
int getP(lista data, int val) {
	for (int i = 0; i < val; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		data = data->next;
	}
	return data->puntuacion;
}
void imprimir(lista data) {
	if (data != NULL) {
		std::cout << data->name << " - " << data->puntuacion << std::endl;
		imprimir(data->next);
	}
}
void ordenarLista(lista& list)
{
	lista actual, siguiente;
	int t;
	std::string t1;
	actual = list;
	while (actual->next != NULL)
	{
		siguiente = actual->next;

		while (siguiente != NULL)
		{
			if (actual->puntuacion > siguiente->puntuacion) {
				t = siguiente->puntuacion;
				t1 = siguiente->name;
				siguiente->puntuacion = actual->puntuacion;
				siguiente->name = actual->name;
				actual->puntuacion = t;
				actual->name = t1;
			}
			siguiente = siguiente->next;
		}
		actual = actual->next;
		siguiente = actual->next;
	}
}

void insertarTXT(lista& list) {
	std::ifstream Doc;
	std::string name = "resources\\Leader.txt";
	Doc.open(name, std::ios::in);
	if (Doc.fail() == true) {//Esta funcion es por si no se puede abrir el txt
		std::cout << "La lista  no se pudo abrir. " << std::endl;
		exit(1);
	}
	std::string** ma = new std::string * [5];
	for (int i = 0; i < 5; i++) {
		ma[i] = new std::string[2];
	}
	for (int i = 0; i < 5; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		for (int j = 0; j < 2; j++) {
			Doc >> ma[i][j];
		}
	}
	for (int i = 0; i < 5; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		int num;
		std::stringstream ss;
		ss << ma[i][1];
		ss >> num;
		insertar(list, ma[i][0], num);
	}
	Doc.close();
	for (int i = 0; i < 5; i++) {
		delete[] ma[i];
	}
}

void leader::mostrar(lista data) {
	fuente = new sf::Font();
	fuente->loadFromFile("resources\\abc.TTF");
	int cont=4;
	int c = 0;
	int y = 330;
	int x = 900;
	lista aux = data;
	while (aux != NULL) {
		Matriz[c] = new sf::Text();
		Matriz[c]->setFont(*fuente);
		Matriz[c]->setString(getName(data,cont));
		Matriz[c]->setPosition(x, y);
		Matriz[c+5] = new sf::Text();
		Matriz[c+5]->setFont(*fuente);
		Matriz[c+5]->setString(std::to_string(getP(data,cont)));
		Matriz[c+5]->setPosition(x+550, y);
		aux = aux->next;
		y = y + 150;
		c++;
		cont--;
	}
}
void agregar(std::string n, int p) {
	lista list = NULL;
	insertarTXT(list);
	ordenarLista(list);
	insertar(list, n, p);
	ordenarLista(list);
	list = list->next;
	std::ofstream Doc;
	std::string name = "resources\\Leader.txt";
	Doc.open(name, std::ios::out);
	if (Doc.fail() == true) {//Esta funcion es por si no se puede abrir el txt
		std::cout << "La lista  no se pudo abrir. " << std::endl;
		exit(1);
	}
	lista aux = list;
	for (int i = 0; i < 5; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		Doc << getName(aux, i);
		Doc << " " << std::to_string(getP(aux, i)) << "\n";
	}
	Doc.close();
}
leader::leader(sf::Vector2i dimension, std::string titulo) {
	fps = 120;
	ventanaX = new sf::RenderWindow(sf::VideoMode(dimension.x, dimension.y), titulo, sf::Style::Fullscreen);
	ventanaX->setFramerateLimit(fps);
	fondo->loadFromFile("resources\\Leader.jpg");
	screen->setTexture(*fondo);
	screen->setScale((float)(ventanaX->getSize().x) / fondo->getSize().x, (float)ventanaX->getSize().y / fondo->getSize().y);
	eventoX = new sf::Event;
	gameover = true;
	data = NULL;
	insertarTXT(data);
	ordenarLista(data);
	mostrar(data);
	gameloop();
}
void leader::gameloop() {

	while (gameover == true) {
		procesar_eventos();
		//LeerDatos();
		dibujar();
		if (eventoX->type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				break;
				
			}
		}
	}
	ventanaX->close();
}
void leader::dibujar() {
	ventanaX->clear();
	ventanaX->draw(*screen);
	for (int i = 0; i < 10; i++) {
		ventanaX->draw(*Matriz[i]);
	}
	ventanaX->display();
}
void leader::procesar_eventos() {
	while (ventanaX->pollEvent(*eventoX)) {

		if (eventoX->type == sf::Event::Closed) {
			ventanaX->close();
			exit(1);
			break;
		}
		break;
	}
}