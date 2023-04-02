/*
 * PartidaMultijugador.cpp
 *
 *  Created on: Mar 30, 2023
 *      Author: franc
 */

#include "PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

PartidaMultijugador::~PartidaMultijugador() {
	// TODO Auto-generated destructor stub
}

PartidaMultijugador::PartidaMultijugador(bool, int, vector<string>){ // @suppress("Class members should be properly initialized")
	this->trasmitidaEnVivo = trasmitidaEnVivo;
	this->cantJugadores = cantJugadores;
	this->participantes = participantes;
}

bool PartidaMultijugador::getTransmitidaEnVivo(){
	return this->trasmitidaEnVivo;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool){
	this->trasmitidaEnVivo = trasmitidaEnVivo;
}

int PartidaMultijugador::getCantJugadores(){
	return this->cantJugadores;
}

void PartidaMultijugador::setCantJugadores(int){
	this->cantJugadores = cantJugadores;
}

vector<string> PartidaMultijugador::getParticipantes(){
	return this->participantes;
}

void PartidaMultijugador::setParticipantes(vector<string>){
	this->participantes = participantes;
}

float PartidaMultijugador::darTotalHorasParticipantes(){
	return this->getDuracion(); //Arreglar
}
