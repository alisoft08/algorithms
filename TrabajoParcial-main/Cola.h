#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include <iostream>
using namespace std;
template <class T>
class Cola
{
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola()
	{
		this->inicio = NULL;
		this->fin = NULL;
	}
	~Cola() {
		while (!esVacia())
		{
			desencolar();
		}
	}
	void encolar(T v);
	T desencolar();
	bool esVacia();
};

//IMPLEMENTACI�N

template <class T>
bool Cola<T>::esVacia()
{
	return (inicio == NULL);
}

template <class T>
void Cola<T>::encolar(T v)
{
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia())
	{
		inicio = nodo;
		fin = inicio;
	}
	else
	{
		fin->sgte = nodo;
		fin = nodo;
	}

	nodo = NULL;
}

template <class T>
T Cola<T>::desencolar()
{
	T dato = inicio->elem;
	if (inicio == fin)
	{
		inicio = NULL;
		fin = NULL;
	}
	else
	{
		inicio = inicio->sgte;
	}
	return dato;
}
#endif 