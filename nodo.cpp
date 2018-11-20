#include"nodo.h"

Nodo::Nodo(){

	this->letra = '-';
	this->hijo = NULL;
	this->hermano = NULL;
}

Nodo::Nodo(char letra, Nodo* hijo, Nodo* hermano){

	this->letra = letra;
	this->hijo = hijo;
	this->hermano = hermano;
}

void Nodo::setLetra(char letra){

	this->letra = letra;
}

void Nodo::setHijo(Nodo* hijo){

	this->hijo = hijo;
}

void Nodo::setHermano(Nodo* hermano){

	this->hermano = hermano;
}

char Nodo::getLetra(){

	return this->letra;
}

Nodo*& Nodo::getHijo(){

	return this->hijo;
}

Nodo*& Nodo::getHermano(){

	return this->hermano;
}

Nodo::~Nodo(){}