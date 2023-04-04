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
using namespace std;

void menu();
void generar();
void crearJugador(string&, int&, string&);
void crearVideojuego(TipoJuego&, string&);
void obtJugadores(int&);
void obtVideojuegos(int&);
void obtPartidas(string&, int&);
void iniPartida(string&, string&, Partida*&);
void darHorasJuego(string&);
void mostrarVector(vector<Jugador*>, int);
void mostrarVector(vector<VideoJuego*>, int);

int main() {
	Sistema *s = new Sistema();
	int opcion = 0, edad, cantJugadores, cantVideojuegos;
	string nickname, contrasenia, nombre, videojuego;
	TipoJuego genero;
	float horas;
	vector<Jugador*> players;
	vector<VideoJuego*> games;

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
			s->agregarVideojuego(nombre, genero);
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
		case 6:
			part = new Partida();
			iniPartida(nickname, videojuego, part);
			break;
		case 7:
			darHorasJuego(videojuego);
			horas = s->buscarVideojuego(videojuego);
			if(horas) {
				cout << "Este videojuego tiene: " << horas << " horas";
			} else {
				cout<< "El videojuego no tiene horas jugadas. \n";
			}
			break;
		case 8:
			generar();
			break;
		default:
			cout << "Ingrese un numero especificado en el menu" << endl;
			break;
		}
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
	cout << "8. Generar usuarios random" << endl;
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

void crearVideojuego(TipoJuego &genero, string &nombre) {
	int a;
	cout << "Ingrese nombre del videojuego: ";
	cin >> nombre;
	fflush(stdin);
	cout << "Elija un genero: " << endl;
	cout
			<< "0. Acción \n 1. Aventura \n 2. Comedia \n 3. Estrategia \n 4. Shooter \n 5. MOBA \n ";
	cin >> a;
	genero = static_cast<TipoJuego>(a);
	fflush(stdin);
}

void generar() {

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

void iniPartida(string &nickname, string &videojuego, Partida *&p) {
	cout << "Ingrese nombre del jugador: ";
	cin >> nickname;
	fflush(stdin);
	cout << "Ingrese nombre del videojuego: ";
	cin >> videojuego;
	fflush(stdin);
}

void darHorasJuego(string& videojuego) {
	cout << "Ingrese nombre del videojuego: ";
	cin >> videojuego;
	fflush(stdin);
}

void mostrarVector(vector<Jugador*> jug, int cant) {
	cout << "LISTA DE JUGADORES" << endl;
	for(auto i: jug) {
		cout << i->getNickname() << endl;
	}
	cout << "Se mostro la cantidad: " << cant << endl;
}

void mostrarVector(vector<VideoJuego*> vid, int cant) {
	cout << "LISTA DE VIDEOJUEGOS" << endl;
	for(auto i: vid) {
		cout << i->getNombre() << endl;
	}
	cout << "Se mostro la cantidad: " << cant << endl;
}
