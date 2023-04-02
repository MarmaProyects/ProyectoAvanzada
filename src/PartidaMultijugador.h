/*
 * PartidaMultijugador.h
 *
 *  Created on: Mar 30, 2023
 *      Author: franc
 */

#ifndef PARTIDAMULTIJUGADOR_H_
#define PARTIDAMULTIJUGADOR_H_
#include<iostream>
#include<string>
#include<vector>
using namespace std;

#include "Partida.h"

class PartidaMultijugador: public Partida {
private:
	bool trasmitidaEnVivo;
	int cantJugadores;
	vector<string> participantes;
public:
	PartidaMultijugador();
	virtual ~PartidaMultijugador();

	PartidaMultijugador(bool, int, vector<string>);

	bool getTransmitidaEnVivo();
	void setTransmitidaEnVivo(bool);

	int getCantJugadores();
	void setCantJugadores(int);

	vector<string> getParticipantes();
	void setParticipantes(vector<string>);

	float darTotalHorasParticipantes();
};

#endif /* PARTIDAMULTIJUGADOR_H_ */
