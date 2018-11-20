#include"arbolP.h"

using namespace std;

ArbolP::ArbolP(){

	this->raiz = NULL;
	this->nivelMax = 0;
}

ArbolP::ArbolP(Nodo* raiz, int nivelMax){

	this->raiz = raiz;
	this->nivelMax = nivelMax;
}

Nodo*& ArbolP::getRaiz(){

	return this->raiz;
}

bool ArbolP::validarCV(string palabra){

	if((palabra[0] != 'A' || palabra[0] != 'E' || palabra[0] != 'I' || palabra[0] != 'O' || palabra[0] != 'U' || palabra[0] != 'a' || palabra[0] != 'e' || palabra[0] != 'i' || palabra[0] != 'o' || palabra[0] != 'u') && (palabra[1] == 'A' || palabra[1] == 'E' || palabra[1] == 'I' || palabra[1] == 'O' || palabra[1] == 'U' || palabra[1] == 'a' || palabra[1] == 'e' || palabra[1] == 'i' || palabra[1] == 'o' || palabra[1] == 'u'))
		return true;
	else
		return false;
	
}

bool ArbolP::validarCCV(string palabra){

	if((palabra[0] != 'A' || palabra[0] != 'E' || palabra[0] != 'I' || palabra[0] != 'O' || palabra[0] != 'U' || palabra[0] != 'a' || palabra[0] != 'e' || palabra[0] != 'i' || palabra[0] != 'o' || palabra[0] != 'u') && (palabra[1] != 'A' || palabra[1] != 'E' || palabra[1] != 'I' || palabra[1] != 'O' || palabra[1] != 'U' || palabra[1] != 'a' || palabra[1] != 'e' || palabra[1] != 'i' || palabra[1] != 'o' || palabra[1] != 'u') && (palabra[2] == 'A' || palabra[2] == 'E' || palabra[2] == 'I' || palabra[2] == 'O' || palabra[2] == 'U' || palabra[2] == 'a' || palabra[2] == 'e' || palabra[2] == 'i' || palabra[2] == 'o' || palabra[2] == 'u'))
		return true;
	else
		return false;
	
}

bool ArbolP::validarCVA(char letra1, char letra2){

	if((letra1 != 'A' || letra1 != 'E' || letra1 != 'I' || letra1 != 'O' || letra1 != 'U' || letra1 != 'a' || letra1 != 'e' || letra1 != 'i' || letra1 != 'o' || letra1 != 'u') && (letra2 == 'A' || letra2 == 'E' || letra2 == 'I' || letra2 == 'O' || letra2 == 'U' || letra2 == 'a' || letra2 == 'e' || letra2 == 'i' || letra2 == 'o' || letra2 == 'u'))
		return true;
	else
		return false;
}

void ArbolP::insertar(Nodo*& raiz, string palabra, int contador){

	if(validarCV(palabra) == true || validarCCV(palabra) == true){

		if(palabra.length()-1 > this->nivelMax)
			this->nivelMax = palabra.length()-1;

		if(raiz != NULL){
		
			if(this->raiz->getLetra() == palabra[0] && this->raiz->getHijo()->getLetra() == palabra[1] && this->raiz->getHijo()->getHijo()->getLetra() == palabra[2]){

				if(raiz->getLetra() == palabra[contador]){

					contador++;
					insertar(raiz->getHijo(), palabra, contador);
				}		
				else{
					insertar(raiz->getHermano(), palabra, contador);
				}
			}
			else if((this->raiz->getLetra() == palabra[0] && this->raiz->getHijo()->getLetra() == palabra[1]) && validarCVA(this->raiz->getLetra(), this->raiz->getHijo()->getLetra())){
	
				if(raiz->getLetra() == palabra[contador]){

					contador++;
					insertar(raiz->getHijo(), palabra, contador);
				}		
				else{
					insertar(raiz->getHermano(), palabra, contador);
				}
			}
			else{

				cout << endl << "La primera sílaba no coincide." << endl;
			}

		}
		else{

			Nodo* nodoRaiz = new Nodo();
			nodoRaiz->setLetra(palabra[contador]);

			raiz = nodoRaiz;

			Nodo* aux = raiz;

			for(int i = contador+1; i < palabra.length(); i++){

				Nodo* nuevoNodo = new Nodo();
				nuevoNodo->setLetra(palabra[i]);
	
				contador++;
	
				aux->setHijo(nuevoNodo);
				aux = aux->getHijo();
			}
		}
	}
	else{

		cout << endl << "La palabra debe comenzar con una consonante y una vocal ó dos consonantes y una vocal." << endl;
	}
}

void ArbolP::mostrarNivel(Nodo* raiz, int nivelRequerido, int nivelActual){

	if(raiz != NULL){


		if(nivelActual == nivelRequerido){

			cout << raiz->getLetra();
		}

		mostrarNivel(raiz->getHijo(), nivelRequerido, nivelActual+1);
		mostrarNivel(raiz->getHermano(), nivelRequerido, nivelActual);
	}
}

void ArbolP::mostrarArbol(){

	for(int nivel = 0; nivel <= this->nivelMax; nivel++){

		mostrarNivel(this->raiz, nivel, 0);
		cout << endl;
	}
}

int ArbolP::getNivelMax(){

	return this->nivelMax;
}
		
ArbolP::~ArbolP(){}
