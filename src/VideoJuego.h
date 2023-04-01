/*
 * VideoJuego.h
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#ifndef VIDEOJUEGO_H_
#define VIDEOJUEGO_H_
#include<iostream>
#include<string>
#include<vector>
#include"Partida.h"
#include"PartidaMultijugador.h"
using namespace std;


enum TipoJuego{
	Accion, Aventura, Comedia, Estrategia, Shooter, MOBA
};

class VideoJuego {
private:
	string nombre;
	TipoJuego genero; //datatype juego
	vector<Partida*> partidas;
	float totalHorasDeJuego;
public:
	VideoJuego();
	VideoJuego(string, TipoJuego);
	virtual ~VideoJuego();

	string getNombre();
	TipoJuego getGenero();

	void setNombre(string);
	void setGenero(TipoJuego);

	float getTotalHorasDeJuego();

	vector<Partida*> getPartidas();
	void agregarPartida(Partida*);

};




#endif /* VIDEOJUEGO_H_ */
