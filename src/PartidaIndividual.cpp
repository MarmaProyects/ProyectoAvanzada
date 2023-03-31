/*
 * PartidaIndividual.cpp
 *
 *  Created on: Mar 30, 2023
 *      Author: franc
 */

#include "PartidaIndividual.h"
#include<iostream>
#include<string>
using namespace std;

PartidaIndividual::PartidaIndividual() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

PartidaIndividual::~PartidaIndividual() {
	// TODO Auto-generated destructor stub
}

PartidaIndividual::PartidaIndividual(bool) { // @suppress("Class members should be properly initialized")
	this->continuaPartidaAnterior = continuaPartidaAnterior;
}

bool PartidaIndividual::getContinuaPartidaAnterior(){
	return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool){
	this->continuaPartidaAnterior = continuaPartidaAnterior;
}

float Partida::darTotalHorasParticipantes(){
	return this->getDuracion();
}
