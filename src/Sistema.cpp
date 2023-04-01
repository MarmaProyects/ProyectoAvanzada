/*
 * Sistema.cpp
 *
 *  Created on: 1 abr. 2023
 *      Author: MarmaduX
 */

#include "Sistema.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#include "Jugador.h"
#include "Partida.h"
#include "VideoJuego.h"

Sistema::Sistema() {
	this->jugadores = new Jugador();
	this->juegos = new VideoJuego();
}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

vector<Jugador*> Sistema::getJugadores() {
	return this->jugadores;
}

vector<VideoJuego*> Sistema::getJuegos() {
	return this->juegos;
}

bool Sistema::existe(string ingreso, string arreglo) {
	if (arreglo == "Jugadores") {
		for (auto i : this->jugadores) {
			Jugador *j = i;
			if (j->getNickname() == ingreso) {
				return true;
			}
		}
	} else {
		for (auto i : this->juegos) {
			VideoJuego *j = i;
			if (j->getNombre() == ingreso) {
				return true;
			}
		}
	}
	return false;
}

void Sistema::agregarJugador(string nickname, int edad, string contrasenia) {
	try {
		if (!this->existe(nickname, "Jugadores")) {
			Jugador *player = new Jugador(nickname, edad, contrasenia);
			this->jugadores.push_back(player);
		} else {
			throw(nickname);
		}
	} catch (exception &nick) {
		cout << "Este jugador ya existe.\n";
		cout << "Nickname: " << nick;
	}
}

void Sistema::agregarVideojuego(string nombre, TipoJuego genero) {
	try {
		if (!this->existe(nombre, "VideoJuegos")) {
			VideoJuego *game = new VideoJuego(nombre, genero);
			this->juegos.push_back(game);
		} else {
			throw(nombre);
		}
	} catch (exception &name) {
		cout << "Este juego ya existe.\n";
		cout << "Juego: " << name;
	}
}

Jugador* Sistema::obtenerJugadores(int &cantJugadores) {
	vector<Jugador*> parteJugadores;
	int j = 0;
	for (auto i : this->jugadores) {
		if (j < cantJugadores) {
			parteJugadores.push_back(i);
			j++;
		} else {
			break;
		}
	}

	if (j < cantJugadores) {
		cantJugadores = j;
	}

	return parteJugadores[0];
}

VideoJuego* Sistema::obtenerVideojuegos(int &cantVideoJuegos) {
	vector<VideoJuego*> parteVideoJuegos;
	int j = 0;
	for (auto i : this->juegos) {
		if (j < cantVideoJuegos) {
			parteVideoJuegos.push_back(i);
			j++;
		} else {
			break;
		}
	}

	if (j < cantVideoJuegos) {
		cantVideoJuegos = j;
	}

	return parteVideoJuegos[0];
}

Partida* Sistema::obtenerPartidas(string videojuego, int &cantPartidas) {
	vector<Partida*> partidasVideoJuego;
	VideoJuego *game;
	int contador = 0;

	for (auto i : this->juegos) {
		if (i->getNombre() == videojuego) {
			game = i;
			break;
		}
	}

	for (auto i : game->getPartidas()) {
		if (contador < cantPartidas) {
			partidasVideoJuego.push_back(i);
		} else {
			break;
		}
	}

	cantPartidas = contador;

	return partidasVideoJuego[0];
}

void Sistema::iniciarPartida(string nickname, string videojuego,
		Partida *datos) {
	try {
		if (this->existe(nickname, "Jugadores")) {
			if(this->existe(videojuego, "Juegos")){

			}else {
				throw(videojuego);
			}
		} else {
			throw(nickname);
		}
	} catch (exception &nick) {
		cout << "Jugador/VideoJuego no valido: " << nick << " \n";
	}
}

