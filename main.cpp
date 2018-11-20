#include"arbolP.h"

int main(){

	ArbolP arbol;

	int opcion, nivel;
	string palabra;

	do{
		cout << endl << "	Menú" << endl;
		cout << "1- Insertar palabra" << endl;
		cout << "2- Mostrar nivel" << endl;
		cout << "3- Mostrar árbol" << endl;
		cout << "4- Salir" << endl;

		cout << endl << "Elija una opción: ";
		cin >> opcion;
		
		switch(opcion){

			case 1:
				cout << endl;
				cout << "Ingrese la palabra: ";
				cin >> palabra;
				arbol.insertar(arbol.getRaiz(), palabra, 0);
				break;
			case 2:
				cout << endl;
				cout << "Ingrese el nivel: ";
				cin >> nivel;
				if(nivel >= 0 && nivel <= arbol.getNivelMax()){
					cout << endl;				
					arbol.mostrarNivel(arbol.getRaiz(), nivel, 0);
				}
				else{						
					cout << endl << "Fuera del rango." << endl;
				}
				break;
			case 3:
				cout << endl;
				arbol.mostrarArbol();
				break;

		}

	}while(opcion != 4);


	return 0;
}