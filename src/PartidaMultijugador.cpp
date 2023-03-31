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

PartidaMultijugador::PartidaMultijugador(bool){ // @suppress("Class members should be properly initialized")
	this->trasmitidaEnVivo = trasmitidaEnVivo;
}

bool PartidaMultijugador::getTransmitidaEnVivo(){
	return this->trasmitidaEnVivo;
}
void PartidaMultijugador::setTransmitidaEnVivo(bool){
	this->trasmitidaEnVivo = trasmitidaEnVivo;
}

float Partida::darTotalHorasParticipantes(){
	return this->getDuracion(); //Arreglar
}
