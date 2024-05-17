#pragma once
#include "Product.h"

class Ticket : public Product {
private:
    //atributos de ticket
    int idTicket;
    float totalPay;
    string tipoVehiculo;
    //atributos de product
    string nameProduct;
    int id;
    float width, height, weight, value;

public:
    Ticket() : Product(" ", 0, 0.0f, 0.0f, 0.0f, 0.0f) {}
    Ticket(int _idTicket, float _totalPay)
        :Product(nameProduct, id, width, height, weight, value),
        idTicket(_idTicket), totalPay(_totalPay) {}
    ~Ticket();

    // Setters
    void setIdTicket(int _id) { idTicket = _id; }
    void setTotalPay(float _totalPay) { totalPay = _totalPay; }

    // Getters
    int getIdTicket()  { return idTicket; }
    float getTotalPay()  { return totalPay; }

    //Metodos de servicio
    void showTicketInfo(string nameProduct, int id, int idTicket, float totalPay, string tipoVehiculo) {
        cout << "============================ Detalles de la boleta ==========================" << endl;
        cout << "|  Producto: " << nameProduct << "                                                        |"<<endl;
        cout << "|  ID del producto: " << id << "                                                        |" << endl;
        cout << "|  ID de la boleta: " << idTicket << "                                                        |" << endl;
        cout << "|  Vehiculo asignado: " << tipoVehiculo << "                                                   |" << endl;
        cout << "|  Precio total: " << totalPay << "                                                          |" << endl;
        cout << " ----------------------------------------------------------------------------"<<endl;
    }
};