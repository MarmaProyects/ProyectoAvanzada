/*
 * DTFecha.cpp
 *
 *  Created on: 1 abr. 2023
 *      Author: MarmaduX
 */

#include "DTFecha.h"

DTFecha::DTFecha() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

DTFecha::~DTFecha() {
	// TODO Auto-generated destructor stub
}

DTFecha::DTFecha(int, int, int){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int DTFecha::getDia(){
	return this->dia;
}

int DTFecha::getMes(){
	return this->mes;
}

int DTFecha::getAnio(){
	return this->anio;
}

