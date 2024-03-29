/*
 * PartidaIndividual.h
 *
 *  Created on: Mar 30, 2023
 *      Author: franc
 */

#ifndef PARTIDAINDIVIDUAL_H_
#define PARTIDAINDIVIDUAL_H_
#include<iostream>
#include<string>
using namespace std;

#include "Partida.h"

class PartidaIndividual: public Partida {
private:
	bool continuaPartidaAnterior;
public:
	PartidaIndividual();
	virtual ~PartidaIndividual();

	PartidaIndividual(DTFecha* fecha, float duracion, bool);

	bool getContinuaPartidaAnterior();
	void setContinuaPartidaAnterior(bool);

	float darTotalHorasParticipantes();
};

#endif /* PARTIDAINDIVIDUAL_H_ */
