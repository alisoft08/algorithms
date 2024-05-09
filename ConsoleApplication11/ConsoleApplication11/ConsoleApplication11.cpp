#include <iostream>
#include <fstream>
#include "ListaDoble.h"
#include "Persona.h"
#include "Cola.h"
using namespace std;

dby::List<Persona*>* listPersonaptr = new dby::List<Persona*>;
dby::Queue<Persona*>* colaBaseDatos = new dby::Queue<Persona*>;
dby::Queue<Persona*>* agenciaBanco = new dby::Queue<Persona*>;

void meterDatos(int i) {

	int edad;
	string nombre;
	float altura;
	
	cout << "Persona " << i + 1 <<":" << endl;
	cout << "edad: "; cin >> edad;
	cout << "nombre: "; cin >> nombre;
	cout << "altura: "; cin >> altura;
	cout << endl;

	Persona* persona = new Persona(edad, nombre, altura, i + 1);
	
	listPersonaptr->insert(i, persona);
	
	colaBaseDatos->push(persona);
	
}


int main() {

	

	ofstream aAlison("alison.txt",ios::app);
	if (aAlison.is_open()) {
		aAlison << "hola alison" << endl;
	}

	int nPersonas = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		meterDatos(nPersonas);
		nPersonas++;
	}
	cout << "LISTA: " << endl;
	int posBuscar;

	cout << "ingresa numero de persona: ";
	cin >> posBuscar;
	posBuscar -= 1;
	listPersonaptr->at(posBuscar)->PrintDatos();
	cout << "POSICION DE REGISTRO: ";
	int pR;
	pR = listPersonaptr->at(posBuscar)->getPosRegistro();
	cout << pR;
	cout << endl;
	
	//ordenar ascendente de menor a mayor
	listPersonaptr->sort([](Persona* a, Persona* b) { return a->getEdad() > b->getEdad(); });


	//ordenar ascendente, de menor a mayor
	/*for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			Persona* aux;
			if (listPersonaptr->at(i)->getEdad() > listPersonaptr->at(j)->getEdad()) {
				aux = listPersonaptr->at(i);
				listPersonaptr->at(i) = listPersonaptr->at(j);
				listPersonaptr->at(j) = aux;
			}
		}
	}*/

	//LISTA ORDENADA
	for (int i = 0; i < n; i++) {
		listPersonaptr->at(i)->PrintDatos();
		cout << "POSICION DE REGISTRO: " << listPersonaptr->at(i)->getPosRegistro() << endl << endl;
	}
	cout << endl;

	float altNueva;
	cout << "Ingrese altura nueva de la persona anterior";
	cin >> altNueva;
	listPersonaptr->at(posBuscar)->setAltura(altNueva);


	for (int i = 0; i < n; i++) {
		listPersonaptr->at(i)->PrintDatos();
	}
	cout << endl;



	
	
	

	//adultos van a cobrar
	cout << "COLA: " << endl;
	int personasEnCola = nPersonas;
	while (personasEnCola--) {
		agenciaBanco->push(colaBaseDatos->extract());
	}

	int personasenAgencia = nPersonas;
	while (personasenAgencia--) {
		agenciaBanco->extract()->PrintDatos();
	}

	
	
	

}