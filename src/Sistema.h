/*
 * Sistema.h
 *
 *  Created on: 1 abr. 2023
 *      Author: MarmaduX
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#include "Jugador.h"
#include "Partida.h"
#include "VideoJuego.h"

enum TipoJuego{
	Accion, Aventura, Comedia, Estrategia, Shooter, MOBA
};

class Sistema{
private:
	vector<Jugador*> jugadores;
	vector<VideoJuego*> juegos;
public:
	Sistema();
	virtual ~Sistema();

	vector<Jugador*> getJugadores();
	vector<VideoJuego*> getJuegos();

	//Operaciones Principales
	bool existe(string, string);
	void agregarJugador(string nickname, int edad, string contrasenia);
	void agregarVideojuego(string nombre, TipoJuego genero);
	Jugador* obtenerJugadores(int& cantJugadores);
	VideoJuego* obtenerVideojuegos(int& cantVideoJuegos);
	Partida* obtenerPartidas(string videojuego, int& cantPartidas);
	void iniciarPartida(string nickname, string videojuego, Partida* datos);
};

#endif /* SISTEMA_H_ */
