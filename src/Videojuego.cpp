/*
 * Videojuego.cpp
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#include "Videojuego.h"

Videojuego::Videojuego() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

Videojuego::Videojuego(string nombre, Tipojuego genero){
	this->nombre = nombre;
	this->genero = genero;
}

Videojuego::~Videojuego() {
	// TODO Auto-generated destructor stub
}

string Videojuego::getNombre(){
	return this->nombre;
}

Tipojuego Videojuego::getGenero(){
	return this->genero;
}

void Videojuego::setNombre(string){
	this->nombre = nombre;
}

void Videojuego::setGenero(Tipojuego){
	this->genero = genero;
}
