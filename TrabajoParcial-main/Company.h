#pragma once
#include "User.h"

class Company : public User {
private:
    string ruc;

public:
    Company(string _username, string _email, string _password, string _ruc)
        : User(_username, _email, _password, "Empresa"), ruc(_ruc) {}

    ~Company() {}

    //setters
    void setRuc(string _ruc) {
        ruc = _ruc;
    }

    //getters
    string getRuc() {
        return ruc;
    }

    void showAdditionalInfo() override {
        cout << "RUC: " << ruc << endl;
    }
};