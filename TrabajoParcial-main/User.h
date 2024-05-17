#pragma once
#include <iostream>
using namespace std;


class User
{
protected:
    string name, email, password, userType;

public:
    User(string _name, string _email, string _password, string _userType)
        : name(_name), email(_email), password(_password), userType(_userType)
    {}
    ~User() {}

    //setters
    void setName(string _name) {
        name = _name;
    }
    void setEmail(string _email) {
        email = _email;
    }
    void setPassword(string _password) {
        password = _password;
    }

    void setUserType(string _userType) {
        userType = _userType;
    }

    //getters
    string getName() {
        return name;
    }

    string getEmail() {
        return email;
    }

    string getPassword() {
        return password;
    }
    string getUserType(){
        return userType;
    } 

  //método para mostrar info del conductor

    virtual void showAdditionalInfo() = 0;

};




