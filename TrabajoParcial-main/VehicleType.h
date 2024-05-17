#pragma once
#include <iostream>
#include "Product.h"
using namespace std;
class VehicleType : public Product
{


public:

	VehicleType()
		: Product(" ", 0, 0.0f, 0.0f, 0.0f, 0.0f) {

	}

	VehicleType(string _nameProduct, int _id, float _width, float _height, float _weight, float _value)
		: Product(_nameProduct, _id, _width, _height, _weight, _value) {}

	string calculateType(int sumaPesoPedido) {

		if (sumaPesoPedido >= 0 && sumaPesoPedido <= 5) {
			return "moto";
		}
		else if (sumaPesoPedido > 5 && sumaPesoPedido <= 40) {
			return "auto";
		}
		else if (sumaPesoPedido > 40 && sumaPesoPedido <= 100) {
			return "camion";
		}
		else
			return "Nuestro servicio no cuenta con el equipo necesario para hacer ese trabajo...";

	}

	~VehicleType() {}







};



