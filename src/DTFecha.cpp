/*
 * DTFecha.cpp
 *
 *  Created on: 1 abr. 2023
 *      Author: MarmaduX
 */

#include "DTFecha.h"

DTFecha::~DTFecha() {
	// TODO Auto-generated destructor stub
}

DTFecha::DTFecha() {
	time_t timer;
		time(&timer);
		struct tm *fecha;
		fecha = localtime(&timer);
		this->dia = fecha->tm_mday;
		this->mes = fecha-> tm_mon + 1;
		this->anio = fecha->tm_year + 1900;
}

int DTFecha::getDia() {
	return this->dia;
}

int DTFecha::getMes() {
	return this->mes;
}

int DTFecha::getAnio() {
	return this->anio;
}

