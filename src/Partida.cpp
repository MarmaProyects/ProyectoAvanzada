/*
 * Partida.cpp
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#include "Partida.h"

Partida::Partida() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

Partida::~Partida() {
	// TODO Auto-generated destructor stub
}

Partida::Partida(DTFecha* fecha, float duracion){ // @suppress("Member declaration not found")
	this->fecha = fecha;
	this->duracion = duracion;
}

DTFecha* Partida::getFecha(){ // @suppress("Member declaration not found")
	return this->fecha;
}

void Partida::setFecha(DTFecha*& fecha){
	this->fecha = fecha;
}

float Partida::getDuracion(){
	return this->duracion;
}

void Partida::setDuracion(float duracion){
	this->duracion = duracion;
}

float Partida::darTotalHorasParticipantes() {
	return this->duracion;
}
