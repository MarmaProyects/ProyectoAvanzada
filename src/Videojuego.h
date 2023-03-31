/*
 * Videojuego.h
 *
 *  Created on: 30 mar. 2023
 *      Author: user
 */

#ifndef VIDEOJUEGO_H_
#define VIDEOJUEGO_H_
#include<iostream>
#include<string>
using namespace std;


enum Tipojuego{
	Accion, Aventura, Comedia, Estrategia, Shooter, MOBA
};

class Videojuego {
private:
	string nombre;
	Tipojuego genero; //datatype juego
public:
	Videojuego();
	Videojuego(string, Tipojuego);
	virtual ~Videojuego();

	string getNombre();
	Tipojuego getGenero();

	void setNombre(string);
	void setGenero(Tipojuego);

};




#endif /* VIDEOJUEGO_H_ */
