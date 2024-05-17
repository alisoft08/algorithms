#pragma once
#include "Nodo.h"

template <class T>
class Pila {
private:
	Nodo<T>* tope; //Puntero al nodo superior de la lista

public:
	Pila() : tope(nullptr) {}
	~Pila();
	void push(T& element);
	void pop();
	bool empty();

};

//Metodo para verificar si la pila esta vacia
template<class T>
bool Pila<T>::empty() { return tope == nullptr; }

//Metodo para agregar un element a la pila
template <class T>
void Pila<T>::push(T& element) {
	Nodo<T>* nuevoNodo = new Nodo<T>(element, tope);
	tope = nuevoNodo;
}

//Metodo para eliminar un element de la pila
template <class T>
void Pila<T>::pop() {
	if (!empty()) {
		Nodo<T>* temp = tope;
		tope = tope->get_Sgte();
		delete temp;
	}
}