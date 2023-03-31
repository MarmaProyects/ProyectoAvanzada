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
using namespace std;

#include "Partida.h"

class PartidaMultijugador: public Partida {
private:
	bool trasmitidaEnVivo;
public:
	PartidaMultijugador();
	virtual ~PartidaMultijugador();

	PartidaMultijugador(bool);

	bool getTransmitidaEnVivo();
	void setTransmitidaEnVivo(bool);

	float Partida:darTotalHorasParticipantes();
};

#endif /* PARTIDAMULTIJUGADOR_H_ */
