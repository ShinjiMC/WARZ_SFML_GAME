#include "Registrar.h"
lista crearR(std::string n, int p) {
	lista nuevo = new Records();
	nuevo->name = n;
	nuevo->puntuacion = p;
	nuevo->next = NULL;
	return nuevo;
}
void insertarR(lista& data, std::string n, int p) {
	if (data == NULL) {
		data = crearR(n, p);
	}
	else {
		insertarR(data->next, n, p);
	}
}
std::string getNameR(lista data, int val) {
	for (int i = 0; i < val; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		data = data->next;
	}
	return data->name;
}
int getPR(lista data, int val) {
	for (int i = 0; i < val; i++) { //crearmos un boocle para poder almacenar los elementos del archivo en una matriz
		data = data->next;
	}
	return data->puntuacion;
}
void imprimirR(lista data) {
	if (data != NULL) {
		std::cout << data->name << " - " << data->puntuacion << std::endl;
		imprimirR(data->next);
	}
}
void ordenarListaR(lista& list)
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

void insertarTXTR(lista& list) {
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
		insertarR(list, ma[i][0], num);
	}
	Doc.close();
	for (int i = 0; i < 5; i++) {
		delete[] ma[i];
	}
}
void agregarR(std::string n, int p) {
	lista list = NULL;
	insertarTXTR(list);
	ordenarListaR(list);
	insertarR(list, n, p);
	ordenarListaR(list);
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
		Doc << getNameR(aux, i);
		Doc << " " << std::to_string(getPR(aux, i)) << "\n";
	}
	Doc.close();
}
Registrar::Registrar(int pun) {
	fps = 120;
	text = ".";
	ventanaX = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Registrar", sf::Style::Fullscreen);
	ventanaX->setFramerateLimit(fps);
	fondo = new sf::Texture;
	screen = new sf::Sprite;
	fondo->loadFromFile("resources\\FondoRes.png");
	screen->setTexture(*fondo);
	screen->setScale((float)(ventanaX->getSize().x) / fondo->getSize().x, (float)ventanaX->getSize().y / fondo->getSize().y);
	eventoX = new sf::Event;
	gameover = true;
	fuente = new sf::Font;
	Matriz = new sf::Text;
	P = new sf::Text;
	AVISO = new sf::Text;
	puntuacion = pun;
	fuente->loadFromFile("resources\\abc.TTF");
	Matriz->setFont(*fuente);
	P->setFont(*fuente);
	AVISO->setFont(*fuente);
	Matriz->setPosition(500, 300);
	P->setPosition(500, 500);
	AVISO->setPosition(500, 700);
	P->setString(std::to_string(puntuacion));
	AVISO->setString("PULSA ESPACIO PARA REGISTRAR");
}
void Registrar::ingresarletra() {
	if (text.size() < 8) {
		if (eventoX->type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				text = text + "A";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				text = text + "Q";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				text = text + "W";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				text = text + "E";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				text = text + "R";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
				text = text + "T";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
				text = text + "Y";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
				text = text + "U";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
				text = text + "I";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
				text = text + "O";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				text = text + "P";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				text = text + "S";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				text = text + "D";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
				text = text + "F";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
				text = text + "G";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
				text = text + "H";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
				text = text + "J";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
				text = text + "K";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
				text = text + "L";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				text = text + "Z";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
				text = text + "X";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
				text = text + "C";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
				text = text + "V";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
				text = text + "B";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
				text = text + "N";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
				text = text + "M";
			}
		}
		Matriz->setString(text);
	}
	

}
void Registrar::gameloop() {

	while (gameover == true) {
		procesar_eventos();
		ingresarletra();
		dibujar();
		if (eventoX->type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				agregarR(text, puntuacion);
				break;
			}
		}
	}
	ventanaX->close();
}
void Registrar::dibujar() {
	ventanaX->clear();
	ventanaX->draw(*screen);
	ventanaX->draw(*Matriz);
	ventanaX->draw(*P);
	ventanaX->draw(*AVISO);
	ventanaX->display();
}
void Registrar::procesar_eventos() {
	while (ventanaX->pollEvent(*eventoX)) {

		if (eventoX->type == sf::Event::Closed) {
			ventanaX->close();
			exit(1);
			break;
		}
		break;
	}
}