#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona
{
private:
	int edad;
	string nombre;
	float altura;
	int posRegistro;
public:
	Persona() {
		this->edad = 0;
		this->nombre = "";
		this->altura = 0.0;
		this->posRegistro = 0;
	}

	Persona(int edad, string nombre, float altura, int posR) : edad(edad), nombre(nombre), altura(altura), posRegistro(posR) {}

	void PrintDatos() {
		cout << this->edad << endl;
		cout << this->nombre << endl;
		cout << this->altura << endl << endl;
	}

	string getNombre() {
		return this->nombre;
	}

	int getEdad() {
		return this->edad;
	}

	//void AumentarPosRegistro() { this->posRegistro++; }
	void setPosicion(int pR) { this->posRegistro = pR; }

	int getPosRegistro() { return this->posRegistro; }

	void setAltura(float altura) { this->altura = altura; }

	~Persona(){}



};



