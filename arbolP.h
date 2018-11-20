#include"nodo.h"
#include<string>

using namespace std;

#ifndef ARBOLP_H
#define ARBOLP_H

class ArbolP{

	private:

		Nodo* raiz;
		int nivelMax;

	public:

		ArbolP();
		ArbolP(Nodo*, int);
		Nodo*& getRaiz();
		bool validarCV(string);
		bool validarCCV(string palabra);
		bool validarCVA(char, char);
		void insertar(Nodo*&, string, int);
		void mostrarNivel(Nodo*, int, int);
		void mostrarArbol();
		int getNivelMax();
		~ArbolP();

};

#endif