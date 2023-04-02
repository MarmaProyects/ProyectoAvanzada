/*
 * Partida.h
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_

#include<iostream>
#include<string>
#include"DTFecha.h"

using namespace std;

class Partida {
private:
	DTFecha* fecha;
	float duracion;
public:
	Partida();
	virtual ~Partida();
	Partida(DTFecha*, float);
	DTFecha* getFecha();
	void setFecha(DTFecha*);
	float getDuracion();
	void setDuracion(float);
	virtual float darTotalHorasParticipantes();
};


#endif /* PARTIDA_H_ */
