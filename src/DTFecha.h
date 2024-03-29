/*
 * DTFecha.h
 *
 *  Created on: 1 abr. 2023
 *      Author: MarmaduX
 */

#ifndef DTFECHA_H_
#define DTFECHA_H_
#include <time.h>

#include<iostream>
#include<string>
using namespace std;
//DataType
class DTFecha {
private:
	int dia;
	int mes;
	int anio;
public:
	DTFecha();
	DTFecha(int, int, int);
	virtual ~DTFecha();

	int getDia();
	int getMes();
	int getAnio();
	string getTime();
};

#endif /* DTFECHA_H_ */
