#pragma once
#include <iostream>
using namespace std;

class Cerdo
{
private:
	float peso;
	int edad;
	double altura;
	float temperatura;
	long codigo;
	int posRegistro;
public:
	Cerdo(){
		this->peso = 0.0;
		this->altura = 0.0;
		this->edad = 0;
		this->temperatura = 0.0;
		this->codigo = 0;
		this->posRegistro = 0;
	}

	Cerdo(float peso, int edad, float altura, float temperatura, long codigo,
		int posR) :peso(peso), edad(edad), altura(altura), codigo(codigo), temperatura(temperatura)
		, posRegistro(posR) {}

	void printDatos() {

		cout << "Cerdo " << this->posRegistro << ": " << endl;
		cout << "Codigo: " << this->codigo << endl;
		cout << "Peso: " << this->peso << " kg" << endl;
		cout << "Edad: " << this->edad << endl;
		cout << "Altura: " << this->altura << " cm" << endl;
		cout << "Temperatura: " << this->temperatura << " °C" << endl << endl;
	}

	int getPosicionRegistro() {
		return this->posRegistro;
	}

	int getEdad() {
		return this->edad;
	}
	float getPeso() {
		return this->peso;
	}
	float getAltura() {
		return this->altura;
	}

	~Cerdo(){}


};

