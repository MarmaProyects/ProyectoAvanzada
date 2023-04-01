/*
 * Videojuego.cpp
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#include "VideoJuego.h"

VideoJuego::VideoJuego() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

VideoJuego::VideoJuego(string nombre, TipoJuego genero){
	this->nombre = nombre;
	this->genero = genero;
}

VideoJuego::~VideoJuego() {
	// TODO Auto-generated destructor stub
}

string VideoJuego::getNombre(){
	return this->nombre;
}

TipoJuego VideoJuego::getGenero(){
	return this->genero;
}

void VideoJuego::setNombre(string){
	this->nombre = nombre;
}

void VideoJuego::setGenero(TipoJuego){
	this->genero = genero;
}

float VideoJuego::getTotalHorasDeJuego(){
	return this->totalHorasDeJuego;
}

vector<Partida*> VideoJuego::getPartidas(){
	return this->partidas;
}

void VideoJuego::agregarPartida(Partida* partida){
	this->partidas.push_back(partida);
	PartidaMultijugador* partidaMult = dynamic_cast<PartidaMultijugador*>(partida);
	if(partidaMult){
		this->totalHorasDeJuego += partidaMult->getDuracion()*partidaMult->getCantJugadores();
	}else{
		this->totalHorasDeJuego += partida->getDuracion();
	}
}
