//============================================================================
// Name        : ProyectoAvanzada.cpp
// Author      : Gaston Aguilera - Franco Sancristobal - Angelo Festino
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#include "Sistema.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Partida.h"
using namespace std;

void menu();
bool validarNumero(string input);
bool validarFloat(string input);
void generar(Sistema*);
void crearJugador(string&, int&, string&);
void crearVideojuego(int&, string&);
void obtJugadores(int&);
void obtVideojuegos(int&);
void obtPartidas(string&, int&);
void iniPartida(string&, string&, Partida*&, Sistema*);
void darHorasJuego(string&);
void mostrarVector(vector<Jugador*>, int);
void mostrarVector(vector<VideoJuego*>, int);
void mostrarVector(vector<Partida*>, int);

int main() {
	Sistema *s = new Sistema();
	int opcion = 0, edad = 0, cantJugadores = 0, cantVideojuegos = 0,
			cantPartidas = 0;
	string nickname, contrasenia, nombre, videojuego;
	int genero;
	float horas;
	vector<Jugador*> players;
	vector<VideoJuego*> games;
	vector<Partida*> matchs;

	Partida *part;
	do {
		fflush(stdin);
		menu();
		cin >> opcion;
		fflush(stdin);
		switch (opcion) {
		case 1:
			crearJugador(nickname, edad, contrasenia);
			s->agregarJugador(nickname, edad, contrasenia);
			break;
		case 2:
			crearVideojuego(genero, nombre);
			s->agregarVideojuego(nombre, (TipoJuego) genero);
			break;
		case 3:
			obtJugadores(cantJugadores);
			players = s->obtenerJugadores(cantJugadores);
			mostrarVector(players, cantJugadores);
			break;
		case 4:
			obtVideojuegos(cantVideojuegos);
			games = s->obtenerVideojuegos(cantVideojuegos);
			mostrarVector(games, cantVideojuegos);
			break;
		case 5:
			iniPartida(nickname, videojuego, part, s);
			s->iniciarPartida(nickname, videojuego, part);
			break;
		case 6:
			obtPartidas(videojuego, cantPartidas);
			matchs = s->obtenerPartidas(videojuego, cantPartidas);
			mostrarVector(matchs, cantPartidas);
			break;
		case 7:
			darHorasJuego(videojuego);
			horas = s->buscarVideojuego(videojuego);
			if (horas) {
				cout << "Este videojuego tiene: " << horas << " horas";
			}
			break;
		default:
			cout << "Ingrese un numero especificado en el menu" << endl;
			break;
		}
		system("sleep 1s");
	} while (opcion != 0);
	return 0;
}

void menu() {
	cout << endl << "Ingrese la opcion que desee usar." << endl;
	cout << "1. Agregar jugadores" << endl;
	cout << "2. Agregar videojuegos" << endl;
	cout << "3. Obtener jugadores" << endl;
	cout << "4. Obtener videojuegos" << endl;
	cout << "5. Iniciar partida" << endl;
	cout << "6. Obtener partidas" << endl;
	cout << "7. Ver total horas de juegos" << endl;
	cout << "0. Salir del programa." << endl;
}

void crearJugador(string &nickname, int &edad, string &contrasenia) {
	string age;
	bool entradaVacia = false;
	cout << "Ingrese nombre del jugador: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	do {
		getline(cin, nickname);
		entradaVacia = std::all_of(nickname.begin(), nickname.end(),
				[](char c) {
					return std::isspace(c);
				});
		if (entradaVacia || nickname.empty()) {
			cout << "El nombre no tiene que ser vacio:";
		}
	} while (entradaVacia || nickname.empty());
	cout << "Ingrese edad del jugador: ";
	cin >> age;
	while (!validarNumero(age)) {
		cout << "La entrada no es un número entero válido." << endl;
		cout << "Ingrese nuevamente: ";
		cin >> age;
	}
	edad = stoi(age);
	cout << "Ingrese contraseña del jugador: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	do {
		getline(cin, contrasenia);
		entradaVacia = std::all_of(contrasenia.begin(), contrasenia.end(),
				[](char c) {
					return std::isspace(c);
				});
		if (entradaVacia || contrasenia.empty()) {
			cout << "La contrasenia no tiene que ser vacio:";
		}
	} while (entradaVacia || contrasenia.empty());

}

void crearVideojuego(int &genero, string &nombre) {
	string entrada;
	bool entradaVacia = false;
	cout << "Ingrese nombre del videojuego: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	do {
		getline(cin, nombre);
		entradaVacia = std::all_of(nombre.begin(), nombre.end(), [](char c) {
			return std::isspace(c);
		});
		if (entradaVacia || nombre.empty()) {
			cout << "El nombre no tiene que ser vacio:";
		}
	} while (entradaVacia || nombre.empty());
	bool bandera = true;
	cout << "Elija un genero: " << endl;
	do {
		cout
				<< "0. Acción \n1. Aventura \n2. Comedia \n3. Estrategia \n4. Shooter \n5. MOBA"
				<< endl;
		cin >> entrada;
		while (!validarNumero(entrada)) {
			cout << "La entrada no es un entero válido." << endl;
			cout << "Ingrese nuevamente: ";
			cin >> entrada;
		}
		genero = stoi(entrada);
		if (genero >= 0 && genero <= 5) {
			bandera = false;
		} else {
			cout << "Elija un numero entre el 0 y 5: " << endl;
		}
	} while (bandera);
	fflush(stdin);
}

void generar(Sistema *s) { //TODO no funciona bien
	s->agregarJugador("MarmaduX", 24, "43242");
	s->agregarVideojuego("Smite", MOBA);
	s->agregarJugador("Judy456", 19, "bgdf435");
	s->agregarVideojuego("CSGO", Shooter);
	s->agregarJugador("Angeloturrito", 22, "432442");
	s->agregarVideojuego("Terraria", Aventura);
	s->agregarJugador("Maleelprofe", 24, "bgd4f435");
	s->agregarVideojuego("GTA", Accion);
	DTFecha *f;
	Partida *part = new PartidaIndividual(f, 24.3, true);
	s->iniciarPartida("Marmadux", "Smite", part);
	part = new PartidaIndividual(f, 35.2, false);
	vector<string> jugadores;
	jugadores.push_back("Marmadux");
	jugadores.push_back("Judy456");
	jugadores.push_back("Angeloturrito");
	jugadores.push_back("Maleelprofe");
	s->iniciarPartida("Marmadux", "Smite", part);
	part = new PartidaMultijugador(f, 76.2, false, 3, jugadores);
	s->iniciarPartida("Marmadux", "Smite", part);
	part = new PartidaMultijugador(f, 43.2, true, 2, jugadores);
	s->iniciarPartida("Angeloturrito", "Smite", part);
	part = new PartidaMultijugador(f, 23.2, true, 4, jugadores);
	s->iniciarPartida("Judy456", "Smite", part);
	cout << "Datos generados correctamente" << endl;
}

void obtJugadores(int &cant) {
	string entrada;
	cout << "Ingrese cantidad de jugadores a obtener: ";
	cin >> entrada;
	while (!validarNumero(entrada)) {
		cout << "La entrada no es un número entero válido." << endl;
		cout << "Ingrese nuevamente: ";
		cin >> entrada;
	}
	cant = stoi(entrada);
	fflush(stdin);
}

void obtVideojuegos(int &cant) {
	string entrada;
	cout << "Ingrese cantidad de videojuegos a obtener: ";
	cin >> entrada;
	while (!validarNumero(entrada)) {
		cout << "La entrada no es un número entero válido." << endl;
		cout << "Ingrese nuevamente: ";
		cin >> entrada;
	}
	cant = stoi(entrada);
	fflush(stdin);
}

void obtPartidas(string &videojuego, int &cant) {
	string entrada;
	bool entradaVacia = false;
	cout << "Ingrese nombre del videojuego: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	do {
		getline(cin, videojuego);
		entradaVacia = std::all_of(videojuego.begin(), videojuego.end(),
				[](char c) {
					return std::isspace(c);
				});
		if (entradaVacia || videojuego.empty()) {
			cout << "El nombre no tiene que ser vacio:";
		}
	} while (entradaVacia || videojuego.empty());
	cout << "Ingrese cantidad de partidas: ";
	cin >> entrada;
	while (!validarNumero(entrada)) {
		cout << "La entrada no es un número entero válido." << endl;
		cout << "Ingrese nuevamente: ";
		cin >> entrada;
	}
	cant = stoi(entrada);
}

void iniPartida(string &nickname, string &videojuego, Partida *&p, Sistema *s) {
	string tipo, booleano, nick;
	string entrada;
	float duracion;
	int cant;
	vector<string> lista;
	vector<Jugador*> players = s->getJugadores();
	cout << "Ingrese nombre del jugador: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, nickname);
	while (!s->existe(nickname, "Jugadores")) {
		cout << "Este jugador no existe: " << nickname << endl;
		cout << "Ingrese nombre del jugador: ";

		getline(cin, nickname);
	}
	cout << "Ingrese nombre del videojuego: ";

	getline(cin, videojuego);
	while (!s->existe(videojuego, "Juegos")) {
		cout << "Este juego no existe: " << videojuego << endl;
		cout << "Ingrese nombre del videojuego: ";

		getline(cin, videojuego);
	}
	do {
		cout << "Que tipo de partida es? I-Individual, M-Multijugador: ";
		cin >> tipo;
		fflush(stdin);
		if (tipo != "I" && tipo != "M") {
			cout << "Valor invalido, debe ingresar I o M ";
		}
	} while (tipo != "I" && tipo != "M");
	cout << "Ingrese duracion de la partida, ejemplo: 34.3: ";
	cin >> entrada;
	while (!validarFloat(entrada)) {
		cout << "La entrada no es un float válido." << endl;
		cout << "Ingrese nuevamente: ";
		cin >> entrada;
	}
	duracion = stof(entrada);
	fflush(stdin);
	DTFecha *f;
	if (tipo == "I") {
		do {
			cout << "Es una continuacion? s/n ";
			cin >> booleano;
			fflush(stdin);
			if (booleano != "s" && booleano != "n") {
				cout << "Valor invalido, debe ingresar s o n " << endl;
			}
		} while (booleano != "s" && booleano != "n");
		if (booleano == "s") {
			p = new PartidaIndividual(f, duracion, true);
		} else {
			p = new PartidaIndividual(f, duracion, false);
		}
	} else {
		do {
			cout << "Es una transmitida en vivo? s/n ";
			cin >> booleano;
			fflush(stdin);
			if (booleano != "s" && booleano != "n") {
				cout << "Valor invalido, debe ingresar s o n: ";
			}
		} while (booleano != "s" && booleano != "n");
		cout << "Cuantos jugadores van a unirse?" << endl;
		cin >> entrada;
		while (!validarNumero(entrada) || !stoi(entrada) != 0) {
			cout << "La entrada no es un entero válido." << endl;
			cout << "Ingrese nuevamente: ";
			cin >> entrada;
		}
		cant = stoi(entrada);
		fflush(stdin);
		while(players.size() < cant) {
			cout << "Se ingresó una cantidad de jugadores mayor a los registrados. \n"
				 << "Ingrese de nuevo: ";
			cin >> entrada;
			cant = stoi(entrada);
		}
		cout << "Ingrese los " << cant << " jugadores:" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (int i = 1; i <= cant; i++) {
			cout << "Jugador N° " << i << endl;
			getline(cin, nick);
			while (!s->existe(nick, "Jugadores")) {
				cout << "El jugador no existe, intente de nuevo: " << endl;
				getline(cin, nick);
			}
			lista.push_back(nick);
		}
		if (booleano == "s") {
			p = new PartidaMultijugador(f, duracion, true, cant, lista);
		} else {
			p = new PartidaMultijugador(f, duracion, false, cant, lista);
		}
	}
}

void darHorasJuego(string &videojuego) {
	bool entradaVacia = false;
	cout << "Ingrese nombre del videojuego: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	do {
		getline(cin, videojuego);
		entradaVacia = all_of(videojuego.begin(), videojuego.end(), [](char c) {
			return isspace(c);
		});
		if (entradaVacia || videojuego.empty()) {
			cout << "El nombre no tiene que ser vacio:";
		}
	} while (entradaVacia || videojuego.empty());
}

void mostrarVector(vector<Jugador*> jug, int cant) {
	cout << "LISTA DE JUGADORES" << endl;
	for (auto i : jug) {
		cout << i->getNickname() << endl;
	}
	cout << "Se mostro la cantidad: " << cant << endl;
}

void mostrarVector(vector<VideoJuego*> vid, int cant) {
	cout << "LISTA DE VIDEOJUEGOS" << endl;
	for (auto i : vid) {
		//cant++;
		cout << i->getNombre() << endl;
	}
	cout << "Se mostro la cantidad: " << cant << endl;
}

bool tiene_caracteres_especiales(string str) {
	for (char c : str) {
		if (!std::isalnum(c)) {
			return true;
		}
	}
	return false;
}

void mostrarVector(vector<Partida*> part, int cant) {
	if (!part.empty()) {
		cout << "LISTA DE PARTIDAS" << endl;
		for (auto i : part) {
			//cant++;
			PartidaIndividual *ind = dynamic_cast<PartidaIndividual*>(i);
			if (ind) {
				cout << "Partida individual con duracion: "
						<< i->getDuracion() << ", el dia "
						<< i->getFecha()->getTime();
				if (ind->getContinuaPartidaAnterior()) {
					cout << " - Es una continuacion de partida.";
				}
				cout << endl;
			} else {
				PartidaMultijugador *mul = dynamic_cast<PartidaMultijugador*>(i);
				cout << "Partida multijugador con duracion: "
						<< i->getDuracion() << " y " << mul->getCantJugadores()
						<< " jugadores," << " el dia "
						<< i->getFecha()->getTime();
				if (mul->getTransmitidaEnVivo()) {
					cout << " - Es transmitida en vivo.";
				}
				cout << endl;
			}
		}
		cout << "Se mostro la cantidad: " << cant << endl;
	}
	else {
		cout << "No tiene partidas. \n";
	}
}

bool validarNumero(string input) {
	bool is_numeric = true;
	for (char c : input) {
		if (!std::isdigit(c)) {
			is_numeric = false;
			break;
		}
	}
	return is_numeric;
}

bool validarFloat(string input) {
	bool is_numeric = true;
	bool primerPunto = true;
	for (char c : input) {
		if (!std::isdigit(c)) {
			if (primerPunto) {
				if (!(c == '.')) {
					is_numeric = false;
					break;
				}
				primerPunto = false;
			} else {
				is_numeric = false;
				break;
			}
		}
	}
	return is_numeric;
}
