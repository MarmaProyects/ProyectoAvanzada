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

#include "Sistema.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Partida.h"
using namespace std;

void menu();
void generar(Sistema*);
void crearJugador(string&, int&, string&);
void crearVideojuego(int&, string&);
void obtJugadores(int&);
void obtVideojuegos(int&);
void obtPartidas(string&, int&);
void iniPartida(string&, string&, Partida*&);
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
			mostrarVector(games, cantJugadores);
			break;
		case 5:
			obtPartidas(videojuego, cantPartidas);
			matchs = s->obtenerPartidas(videojuego, cantPartidas);
			mostrarVector(matchs, cantPartidas);
			break;
		case 6:
			iniPartida(nickname, videojuego, part);
			s->iniciarPartida(nickname, videojuego, part);
			break;
		case 7:
			darHorasJuego(videojuego);
			horas = s->buscarVideojuego(videojuego);
			if (horas) {
				cout << "Este videojuego tiene: " << horas << " horas";
			} else {
				cout << "El videojuego no tiene horas jugadas. \n";
			}
			break;
		case 8:
			generar(s);
			break;
		default:
			cout << "Ingrese un numero especificado en el menu" << endl;
			break;
		}
		system("sleep 3s");
	} while (opcion != 0);
	return 0;
}

void menu() {
	cout << endl << "Ingrese la opcion que desee usar." << endl;
	cout << "1. Agregar jugadores" << endl;
	cout << "2. Agregar videojuegos" << endl;
	cout << "3. Obtener jugadores" << endl;
	cout << "4. Obtener videojuegos" << endl;
	cout << "5. Obtener partidas" << endl;
	cout << "6. Iniciar partida" << endl;
	cout << "7. Ver total horas de juegos" << endl;
	cout << "8. Generar datos" << endl;
	cout << "0. Salir del programa." << endl;
}

void crearJugador(string &nickname, int &edad, string &contrasenia) {
	cout << "Ingrese nombre del jugador: ";
	cin >> nickname;
	fflush(stdin);
	cout << "Ingrese edad del jugador: ";
	cin >> edad;
	fflush(stdin);
	cout << "Ingrese contraseña del jugador: ";
	cin >> contrasenia;
	fflush(stdin);
}

void crearVideojuego(int &genero, string &nombre) {
	cout << "Ingrese nombre del videojuego: ";
	cin >> nombre;
	fflush(stdin);
	cout << "Elija un genero: " << endl;
	cout
			<< "0. Acción \n1. Aventura \n2. Comedia \n3. Estrategia \n4. Shooter \n5. MOBA"
			<< endl;
	cin >> genero;
	fflush(stdin);
}

void generar(Sistema *s) {
	s->agregarJugador("Marma", 24, "43242");
	s->agregarVideojuego("Smite", MOBA);
	s->agregarJugador("Judy", 19, "bgdf435");
	s->agregarVideojuego("CS GO", Shooter);
	s->agregarJugador("Angelo", 22, "432442");
	s->agregarVideojuego("Terraria", Aventura);
	s->agregarJugador("Male", 24, "bgd4f435");
	s->agregarVideojuego("GTA Vice City", Accion);
	DTFecha* f;
	Partida* part = new PartidaIndividual(f, 24.3, true);
	s->iniciarPartida("Marma", "Smite", part);
	part = new PartidaIndividual(f, 35.2, false);
	vector<string> jugadores;
	jugadores.push_back("Marma");
	jugadores.push_back("Judy");
	jugadores.push_back("Angelo");
	jugadores.push_back("Male");
	s->iniciarPartida("Marma", "Smite", part);
	part = new PartidaMultijugador(f, 76.2, false, 3, jugadores);
	s->iniciarPartida("Marma", "Smite", part);
	part = new PartidaMultijugador(f, 43.2, true, 2, jugadores);
	s->iniciarPartida("Angelo", "Smite", part);
	part = new PartidaMultijugador(f, 23.2, true, 4, jugadores);
	s->iniciarPartida("Judy", "Smite", part);
	cout<< "Datos generados correctamente"<< endl;
}

void obtJugadores(int &cant) {
	cout << "Ingrese cantidad de jugadores a obtener: ";
	cin >> cant;
	fflush(stdin);
}

void obtVideojuegos(int &cant) {
	cout << "Ingrese cantidad de videojuegos a obtener: ";
	cin >> cant;
	fflush(stdin);
}

void obtPartidas(string &videojuego, int &cant) {
	cout << "Ingrese nombre del videojuego: ";
	cin >> videojuego;
	fflush(stdin);
	cout << "Ingrese cantidad de partidas: ";
	cin >> cant;
	fflush(stdin);
}

void iniPartida(string &nickname, string &videojuego, Partida* &p) {
	string tipo, booleano, nick;
	float duracion;
	int cant;
	vector<string> lista;
	cout << "Ingrese nombre del jugador: ";
	cin >> nickname;
	fflush(stdin);
	cout << "Ingrese nombre del videojuego: ";
	cin >> videojuego;
	fflush(stdin);
	do {
		cout << "Que tipo de partida es? I-Individual, M-Multijugador: ";
		cin >> tipo;
		fflush(stdin);
		if (tipo != "I" && tipo != "M") {
			cout << "Valor invalido, debe ingresar I o M ";
		}
	} while (tipo != "I" && tipo != "M");
	cout << "Ingrese duracion de la partida, ejemplo: 34.3: ";
	cin >> duracion;
	fflush(stdin);
	DTFecha * f;
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
	}else {
		do {
			cout << "Es una transmitida en vivo? s/n ";
			cin >> booleano;
			fflush(stdin);
			if (booleano != "s" && booleano != "n") {
				cout << "Valor invalido, debe ingresar s o n: ";
			}
		} while (booleano != "s" && booleano != "n");
		cout << "Cuantos jugadores van a unirse?" << endl;
		cin >> cant;
		fflush(stdin);
		cout << "Ingrese los " << cant << " jugadores:" << endl;
		for (int i = 0; i < cant; i++) {
			cout << "Jugador N° " << i << endl;
			cin >> nick;
			fflush(stdin);
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
	cout << "Ingrese nombre del videojuego: ";
	cin >> videojuego;
	fflush(stdin);
}

void mostrarVector(vector<Jugador*> jug, int cant) {
	cout << "LISTA DE JUGADORES" << endl;
	for (auto i : jug) {
		cout << i->getNickname() << endl;
	}
	cout << "Se mostro la cantidad : " << cant << endl;
}

void mostrarVector(vector<VideoJuego*> vid, int cant) {
	cout << "LISTA DE VIDEOJUEGOS" << endl;
	for (auto i : vid) {
		//cant++;
		cout << i->getNombre() << endl;
	}
	cout << "Se mostro la cantidad: " << cant << endl;
}

void mostrarVector(vector<Partida*> part, int cant) {
	cout << "LISTA DE PARTIDAS" << endl;
	for (auto i : part) {
		//cant++;
		PartidaIndividual* ind = dynamic_cast<PartidaIndividual*>(i);
		if(ind){
			cout << "Una partida individual con duracion: " << i->getDuracion() << " el dia " << i->getFecha()->getTime() << endl;
		}else{
			PartidaMultijugador* mul = dynamic_cast<PartidaMultijugador*>(i);
			cout << "Una partida multijugador con duracion: " << i->getDuracion() << " y " << mul->getCantJugadores() << " jugadores" << " el dia " << i->getFecha()->getTime() << endl;
		}
	}
	cout << "Se mostro la cantidad: " << cant << endl;
}
