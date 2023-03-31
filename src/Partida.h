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
using namespace std;

enum DTfecha{
	DIA, MES, ANIO
};
class Partida {
private:
	DTfecha fecha;
	float duracion;
public:
	Partida();
	virtual ~Partida();
	Partida(DTfecha, float);
	DTfecha getFecha();
	void setFecha(DTfecha);
	float getDuracion();
	void setDuracion(float);
	virtual float darTotalHorasParticipantes();
};


#endif /* PARTIDA_H_ */
