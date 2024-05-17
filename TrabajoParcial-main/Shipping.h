#pragma once
#include "Product.h"


class Shipping : public Product {

public:

    Shipping()
        : Product("", 0 , 0.0f, 0.0f, 0.0f, 0.0f) {
        // Constructor por defecto
    }

    Shipping(string _nameProduct, int _id, float _width, float _height, float _weight, float _value)
        : Product(_nameProduct, _id, _width, _height, _weight, _value) {
        // Aquí puedes inicializar variables específicas de Shipping
    }
    ~Shipping() {}
    float calculatePrice(int sumaPesoPedido, float distance) { //retorna el precio estimado por peso y distancia
        int InitialPrice = 10;
        float weightEstimate;
        float distanceEstimate;
        weightEstimate = (float)sumaPesoPedido * 5 + InitialPrice; //se inicia con 10 soles y por cada kg extra se aumenta de 5 en 5 soles
        distanceEstimate = (float)distance;
        //la distancia es 1 sol por cada kilometro

        return weightEstimate + distanceEstimate;
    }
};

