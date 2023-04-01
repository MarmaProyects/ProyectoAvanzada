/*
 * DTFecha.h
 *
 *  Created on: 1 abr. 2023
 *      Author: MarmaduX
 */

#ifndef DTFECHA_H_
#define DTFECHA_H_

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

};

#endif /* DTFECHA_H_ */
