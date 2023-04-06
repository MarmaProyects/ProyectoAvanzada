/*
 * PartidaIndividual.cpp
 *
 *  Created on: Mar 30, 2023
 *      Author: franc
 */

#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(){ // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

PartidaIndividual::~PartidaIndividual() {
	// TODO Auto-generated destructor stub
}

PartidaIndividual::PartidaIndividual(DTFecha* fecha, float duracion, bool continuaPartidaAnterior): Partida(fecha, duracion) { // @suppress("Class members should be properly initialized")
	this->continuaPartidaAnterior = continuaPartidaAnterior;
}

bool PartidaIndividual::getContinuaPartidaAnterior(){
	return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool continuaPartidaAnterior){
	this->continuaPartidaAnterior = continuaPartidaAnterior;
}

float PartidaIndividual::darTotalHorasParticipantes(){
	return this->getDuracion();
}
