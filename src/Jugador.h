/*
 * Jugador.h
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include<iostream>
#include<string>
using namespace std;

class Jugador {
private:
	string nickname;
	int edad;
	string contrasenia;

public:
	Jugador();
	virtual ~Jugador();
	Jugador(string,int,string);
	string getNickname();
	int getEdad();
	string getContrasenia();
	void setNickname(string);
	void setEdad(int);
	void setContrasenia(string);
};

#endif /* JUGADOR_H_ */
