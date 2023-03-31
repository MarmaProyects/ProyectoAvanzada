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

Partida::Partida(DTfecha fecha, float duracion){
	this->fecha = fecha;
	this->duracion = duracion;
}

DTfecha Partida::getFecha(){
	return this->fecha;
}

void Partida::setFecha(DTfecha){
	this->fecha = fecha;
}

float Partida::getDuracion(){
	return this->duracion;
}

void Partida::setDuracion(float){
	this->duracion = duracion;
}
