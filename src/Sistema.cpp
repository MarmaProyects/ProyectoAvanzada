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
#include <time.h>

using namespace std;

#include "Jugador.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "VideoJuego.h"

Sistema::Sistema() {
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
			if (i->getNickname() == ingreso) {
				return true;
			}
		}
	} else {
		for (auto i : this->juegos) {
			if (i->getNombre() == ingreso) {
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
	} catch (string &nick) {
		cout << "Este jugador ya existe.\n";
		cout << "Nickname: " << nick << endl;
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
	} catch (string &name) {
		cout << "Este juego ya existe.\n";
		cout << "Juego: " << name << endl;
	}
}

vector<Jugador*> Sistema::obtenerJugadores(int &cantJugadores) {
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

	return parteJugadores;
}

vector<VideoJuego*> Sistema::obtenerVideojuegos(int &cantVideoJuegos) {
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
	return parteVideoJuegos;
}

vector<Partida*> Sistema::obtenerPartidas(string videojuego,
		int &cantPartidas) {

	vector<Partida*> partidasVideoJuego;
	VideoJuego *game;
	int contador = 0;
	try {
		if (this->existe(videojuego, "Juegos")) {
			for (auto i : this->juegos) {
				if (i->getNombre() == videojuego) {
					game = i;
					break;
				}
			}
			if (game) {
				for (auto i : game->getPartidas()) {
					if (contador < cantPartidas) {
						partidasVideoJuego.push_back(i);
						contador++;
					} else {
						break;
					}
				}
			}
			cantPartidas = contador;
		} else {
			throw(videojuego);
		}
	} catch (string &juego) {
		cout << "El juego no existe: " << juego << endl;
	}
	return partidasVideoJuego;
}

void Sistema::iniciarPartida(string nickname, string videojuego,
		Partida *datos) {
	try {
		if (this->existe(nickname, "Jugadores")) {
			if (this->existe(videojuego, "Juegos")) {
				DTFecha *f = new DTFecha();
				datos->setFecha(f);
				for (auto i : this->getJugadores()) {
					if (i->getNickname() == nickname) {
						i->agregarPartida(datos);
						break;
					}
				}
				for (auto j : this->getJuegos()) {
					if (j->getNombre() == videojuego) {
						j->agregarPartida(datos);
						break;
					}
				}
			} else {
				throw(videojuego);
			}
		} else {
			throw(nickname);
		}
	} catch (string &nick) {
		cout << "Jugador/VideoJuego no valido: " << nick << endl;
	}
}

float Sistema::buscarVideojuego(string videojuego) {
	try {
		if (this->existe(videojuego, "Juegos")) {
			for (auto i : this->getJuegos()) {
				if (i->getNombre() == videojuego) {
					return i->getTotalHorasDeJuego();
				}
			}
		} else {
			throw(videojuego);
		}
	} catch (string &videojuego) {
		cout << "VideoJuego no valido: " << videojuego << endl;
	}
	return NULL;
}
