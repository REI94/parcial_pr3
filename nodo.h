#include<iostream>

#ifndef NODO_H
#define NODO_H

class Nodo{

	private:

		char letra;
		Nodo* hijo;
		Nodo* hermano;

	public:

		Nodo();
		Nodo(char, Nodo*, Nodo*);
		void setLetra(char);
		void setHijo(Nodo*);
		void setHermano(Nodo*);
		char getLetra();
		Nodo*& getHijo();
		Nodo*& getHermano();
		~Nodo();

};

#endif