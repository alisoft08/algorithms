#pragma once
#include "Ticket.h"

class Order : public Ticket {

public:
	Order() : Ticket(0, 0.0f) {

	}
	~Order();

	void showOrder(int id, int idTicket) {
		cout << " ============= ORDEN DEL PRODUCTO ============== " << endl;
		cout << "Orden del Producto: " << id << endl;
		cout << "Orden de la boleta: " << idTicket << endl;
		cout << "TOTAL: " << this->getTotalPay() << endl;
	}
};