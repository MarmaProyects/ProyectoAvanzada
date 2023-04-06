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
#include<vector>
#include"Partida.h"
using namespace std;

class Jugador {
private:
	string nickname;
	int edad;
	string contrasenia;
	vector<Partida*> partidasIniciadas;
	//vector<Partida*> partidasMultujugador;
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
	vector<Partida*>getpartidasIniciadas();
	void agregarPartida(Partida*&);
};

#endif /* JUGADOR_H_ */
