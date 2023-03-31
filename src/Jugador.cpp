/*
 * Jugador.cpp
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#include "Jugador.h"

Jugador::Jugador() {
	// TODO Auto-generated constructor stub

}
Jugador::Jugador(string nickname, int edad, string contrasenia){ // @suppress("Class members should be properly initialized")
	this->nickname = nickname;
	this->edad = edad;
	this->contrasenia = contrasenia;
}

string Jugador::getNickname(){
	return this->nickname;
}

int Jugador::getEdad(){
	return this->edad;
}

string Jugador::getContrasenia(){
	return this->contrasenia;
}

void Jugador::setNickname(string){
	this->nickname = nickname;
}

void Jugador::setEdad(int){
	this->edad = edad;
}s
void Jugador::setContrasenia(string){
	this->contrasenia = contrasenia;
}

Jugador::~Jugador() {
	// TODO Auto-generated destructor stub
}

