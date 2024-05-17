#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
private:

    string brand, model, plate;
    int year;
    

public:

    Vehicle(string _brand, string _model, int _year)
        : brand(_brand), model(_model), year(_year)
    {}

    ~Vehicle() {}

    void setBrand(string _brand) {
        brand = _brand;
    }

    void setModel(string _model) {
        model = _model;
    }

    void setYear(int _year) {
        year = _year;
    }

    string getBrand() {
        return brand;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }




};


