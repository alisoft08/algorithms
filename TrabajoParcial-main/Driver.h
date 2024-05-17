#pragma once
#include <iostream>
using namespace std;
class Driver : public User
{
private:
    string driverLicense, model;
    double rating;
public:
    Driver(string _username, string _email, string _password, string _driverLicense, string _model)
        : User(_username, _email, _password, "Conductor"), driverLicense(_driverLicense), model(_model) {}

    ~Driver() {}


    //setters
    void setName(string _name) {
        name = _name;
    }
    void setDriverLicense(string _driverLicense) {
        driverLicense = _driverLicense;
    }

    void setRating(double _rating) {
        rating = _rating;
    }
    void setModel(string _model) {
        model = _model;
    }

    //getters
    string getName() {
        return name;
    }
    double getRating() {
        return rating;
    }
    string getDriverLicense() {
        return driverLicense;
    }
    string getModel() {
        return model;
    }

    void showAdditionalInfo() override {
        cout << "Licencia de conducir: " << driverLicense << endl;
        cout << "Modelo de auto: " << model << endl;
    }

};

