#pragma once
#include "User.h"

class Person : public User {
private:
    string dni;

public:
    Person(string _username, string _email, string _password, string _dni)
        : User(_username, _email, _password, "Persona"), dni(_dni) {}

    ~Person() {}

    //setters
    void setDni(string _dni) {
        dni = _dni;
    }

    //getters
    string getDni() {
        return dni;
    }

    void showAdditionalInfo() override {
        cout << "DNI: " << dni << endl;
    }
};