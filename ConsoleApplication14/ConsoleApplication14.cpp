#include <iostream>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include "Lista.h"
#include "Cola.h"
#include "Cerdo.h"

using namespace std;




dby::List<Cerdo*>* listaCerdos = new dby::List<Cerdo*>;
dby::List<Cerdo*>* listaCerdosOrdenada = new dby::List<Cerdo*>;
dby::Queue<Cerdo*>* colaCerdos = new dby::Queue<Cerdo*>;

//for (int i = 0; i < cantCerdos; i++) {
//	cout << "Cerdo " << i + 1 << ": " << endl;
//	codigo = rand() % (9999 - 1001) + 1;
//	cout << "Ingrese codigo: ";
//
//	cin >> codigo;
//	cout << "Ingrese peso: ";
//	cin >> peso;
//	cout << "Ingrese edad: ";
//	cin >> edad;
//	cout << "Ingrese altura: ";
//	cin >> altura;
//	cout << "Ingrese temperatura: ";
//	cin >> temperatura;
//	cout << endl;

double calcularPromedioRecursivoAlturas(int tamano, int indice = 0, double suma = 0) {

	if (indice == tamano) {

		return suma / tamano;
	}
	else {

		suma += listaCerdos->at(indice)->getAltura();
		return calcularPromedioRecursivoAlturas(tamano, indice + 1, suma);
	}
}

double calcularPromedioRecursivoPesos(int tamano, int indice = 0, double suma = 0) {
	
	if (indice == tamano) {
		
		return suma / tamano;
	}
	else {
		
		suma += listaCerdos->at(indice)->getPeso();
		return calcularPromedioRecursivoPesos(tamano, indice + 1, suma);
	}
}

double calcularPromedioRecursivoEdades(int tamano, int indice = 0, double suma = 0) {

	if (indice == tamano) {

		return suma / tamano;
	}
	else {

		suma += listaCerdos->at(indice)->getEdad();
		return calcularPromedioRecursivoEdades(tamano, indice + 1, suma);
	}
}

void llenarDatos(int& iterador, long long& cantTotalCerdos) {

	long cantidadCerdos;
	float peso;
	int edad;
	float altura;
	float temperatura;
	long codigo;

	/*do {*/
		cout << "Ingrese la cantidad de cerdos a registrar: "; cin >> cantidadCerdos;
	/*} while (cantCerdos < 500 || cantCerdos>800);*/


	for (int i = 0; i < cantidadCerdos; i++) {
		codigo = rand() % (9999 - 1001) + 1001;
		edad = rand() % (15 - 1) + 1;

		peso = rand() % (40000 - 3000) + 3000;
		peso = (float)peso / 100;

		altura = rand() % (200 - 50) + 50;
		altura = (float)altura / 100;

		temperatura = rand() % (400 - 300) + 300;
		temperatura = (float)temperatura / 10;

		Cerdo* cerdo = new Cerdo(peso, edad, altura, temperatura, codigo, iterador + 1);
		listaCerdos->insert(iterador, cerdo);
		colaCerdos->push(cerdo);
		iterador++;
	}

	cantTotalCerdos += cantidadCerdos;

}

void ordInsercion(long long n) {

	Cerdo* aux;
	int auxentero;
	int k;

	for (int i = 0; i < n; i++) {
		listaCerdosOrdenada->insert(i, listaCerdos->at(i));
	}

	for (int i = 1; i < n; i++) {
		aux = listaCerdosOrdenada->at(i);
		auxentero = listaCerdosOrdenada->at(i)->getEdad();
		k = i - 1;

		while (k >= 0 && auxentero < listaCerdosOrdenada->at(k)->getEdad()) {

			listaCerdosOrdenada->at(k + 1) = listaCerdosOrdenada->at(k);
			k--;
		}
		listaCerdosOrdenada->at(k + 1) = aux;
	}
}

int printMenu() {

		cout << "INGRESE LA OPCION QUE DESEE: " << endl << endl;
		cout << "1. Ingresar cantidad de cerdos a registrar (aleatorio)" << endl;
		cout << "2. Mostrar lista de cerdos (desordenada)" << endl;
		cout << "3. Mostrar lista ordenada segun edad (ordenamiento de insercion - ascendente)" << endl;
		cout << "4. Mostrar edades del cerdo segun orden de registro (cola)" << endl;
		cout << "5. Calcular promedio edades (recursividad)" << endl;
		cout << "6. Calcular promedio pesos (recursividad)" << endl;
		cout << "7. Calcular promedio alturas (recursividad)" << endl;
		cout << "8. Salir" << endl;

		

	int opcion;
	do
	{
		cin >> opcion;
		if (opcion < 1 || opcion>8)
			cout << "Ingrese una opcion valida... ";

	} while (opcion < 1 || opcion>8);

	return opcion;
}

int main()
{
	
	int iterador = 0;
	long long cantTotalCerdos = 0;
	long long cerdosEncolados = 0;
	int iteradorCola = 1;

	srand(time(NULL));
	
	int opcion = 0;
	while (opcion != 8) {
		
		
		system("cls");
		opcion = printMenu();

		switch (opcion)
		{
		case 1:
			llenarDatos(iterador, cantTotalCerdos);
			cerdosEncolados = cantTotalCerdos;
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;

		case 2:

			if (cantTotalCerdos < 1) {
				cout << "Primero registre cerdos..." << endl;
			}
			else {
				for (int i = 0; i < cantTotalCerdos; i++) {
					
					listaCerdos->at(i)->printDatos();
				}
			}
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			
			break;
		case 4:
			
			if (colaCerdos->empty()) {
				cout << "No hay cerdos encolados..." << endl;
			}
			else {
				cerdosEncolados = colaCerdos->size();
				while (cerdosEncolados--) {
					cout << "Edad " << iteradorCola << ": ";
					cout << colaCerdos->extract()->getEdad() << endl;
					iteradorCola++;
				}
			}
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;

		case 3:

			if (cantTotalCerdos < 1) {
				cout << "Primero registre cerdos..." << endl;
			}
			else {
				ordInsercion(cantTotalCerdos);
				for (int i = 0; i < cantTotalCerdos; i++) {
					listaCerdosOrdenada->at(i)->printDatos();
				}
			}
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;

		case 5:
			double promEdadCerdos;
			if (cantTotalCerdos < 1) {
				cout << "Primero registre cerdos..." << endl;
			}
			else {
				promEdadCerdos = calcularPromedioRecursivoEdades(cantTotalCerdos);
				cout << "PROMEDIO EDADES: " << promEdadCerdos << endl;
			}
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;

		case 6:
			double promPesosCerdos;
			if (cantTotalCerdos < 1) {
				cout << "Primero registre cerdos..." << endl;
			}
			else {
				promPesosCerdos = calcularPromedioRecursivoPesos(cantTotalCerdos);
				cout << "PROMEDIO PESOS: " << promPesosCerdos << endl;
			}
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;

		case 7:
			double promAlturasCerdos;
			if (cantTotalCerdos < 1) {
				cout << "Primero registre cerdos..." << endl;
			}
			else {
				promAlturasCerdos = calcularPromedioRecursivoAlturas(cantTotalCerdos);
				cout << "PROMEDIO ALTURAS: " << promAlturasCerdos << endl;
			}
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;
		}
	}
}

