#include <cstdlib>
#include <iostream>
#include <string>
#include <functional>
#include "User.h"
#include "Lista.h"
#include "Driver.h"
#include "Product.h"
#include "Ticket.h"
#include "Order.h"
#include "Person.h"
#include "Company.h"
#include <stdio.h>
#include <conio.h>
#include "Cola.h"
#include "Shipping.h"
#include "VehicleType.h"
#include "OrderTracking.h"
#include "List.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;


dby::List<User*>* listUsers = new dby::List<User*>;
dby::List<Product*>* listProducts = new dby::List<Product*>;
dby::List<Order*>* listOrders = new dby::List<Order*>;

dby::Queue<Order*>* arrivalOrder = new dby::Queue<Order*>;
dby::Stack<Order*>* recentModifications = new dby::Stack<Order*>;


void showMenu() {
    int option;
    cout << "          _    _ _           _     ___" << std::endl;
    cout << "         | |  | | |         | |   |_  |" << std::endl;
    cout << "         | |  | | |__   __ _| |_    | | ___  _   _ _ __ _ __   ___ _   _" << std::endl;
    cout << "         | |\\/| | '_ \\ / _` | __|   | |/ _ \\| | | | '__| '_ \\ / _ \\ | | |" << std::endl;
    cout << "         \\  /\\  / | | | (_| | |_/\\__/ / (_) | |_| | |  | | | |  __/ |_| |" << std::endl;
    cout << "          \\/  \\/|_| |_|\\__,_|\\__|\\____/\\___/ \\__,_|_|  |_| |_|\\___|\\__, |" << std::endl;

    cout << "  |'''''||'''''||'''''||'''''||'''''||'''''||'''''||'''''||'''''||'__/  |'''''|| '''''| " << endl;
    cout << "  '-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-0-0-''-|___/ -0-0-''`-0-0-'" << endl;

    cout << " ------------------------------------------------------------" << endl;
    cout << "|                                                            |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   1   |           Registrar usuario                        |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   2   |           Iniciar sesion                           |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   3   |           Mostrar usuarios                         |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << "|   4   |           Salir                                    |" << endl;
    cout << " ------------------------------------------------------------" << endl;

}


//REGISTRAR USUARIO DE ACUERDO AL TIPO
void registerUser(Lista<User*>& users1) {
    string username, email, password, licenseNumber, vehicleModel, dni, ruc;
    int userType;
    cout << " Ingrese el tipo de usuario (1: Empresa, 2: Persona, 3: Conductor): " << endl;
    cout << " --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---" << endl;

    cin >> userType;

    switch (userType) {
    case 1: {
        cout << "Ingresa el nombre de tu empresa: ";
        cin.ignore();
        getline(cin, username);
        cout << "Ingresa tu correo electronico: ";
        cin >> email;
        cout << "Crea tu contrasenia: ";
        cin >> password;
        cout << "Ingrese tu numero de RUC: ";
        cin >> ruc;
        users1.agregaPos(new Company(username, email, password, ruc), users1.longitud());
        break; //PARA EMPRESAS
    }
    case 2: {
        cout << "Ingresa tu nombre y apellido: ";
        cin.ignore();
        getline(cin, username);
        cout << "Ingresa tu correo electronico: ";
        cin >> email;
        cout << "Crea tu contrasenia: ";
        cin >> password;
        cout << "Ingrese tu numero de DNI: ";
        cin >> dni;
        users1.agregaPos(new Person(username, email, password, dni), users1.longitud());
        break;  //PARA PERSONA 
    }
    case 3: {
        cout << "Ingresa tu nombre y apellido: ";
        cin.ignore();
        getline(cin, username);
        cout << "Ingresa tu correo electronico: ";
        cin >> email;
        cout << "Crea tu contrasenia: ";
        cin >> password;
        cout << "Ingrese tu numero de licencia de conducir: ";
        cin >> licenseNumber;
        cout << "Ingrese el modelo de tu vehiculo: ";
        cin >> vehicleModel;
        users1.agregaPos(new Driver(username, email, password, licenseNumber, vehicleModel), users1.longitud());
        break; //PARA CONDUCTOR
    }
    default:
        cout << "Tipo de usuario invalido." << endl;
        return;
    }
    cout << "Usuario registrado exitosamente." << endl;

}


void showUsers(Lista<User*>& users2) {

    cout << "Usuarios registrados" << endl;
    for (uint i = 0; i < users2.longitud(); i++)
    {
        User* user = users2.obtenerPos(i); cout << endl;
        cout << "USUARIO " << i + 1 << ": " << endl;
        cout << "--- --- --- --- --- --- --- " << endl;
        cout << "TIPO DE USUARIO: " << user->getUserType() << endl;
        cout << "--- --- --- --- --- --- --- " << endl;
        cout << "Nombre de usuario: " << user->getName() << endl;
        cout << "Correo electronico: " << user->getEmail() << endl;
        user->showAdditionalInfo();


    }
}
/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
void showMenuOrder(int e) {
   
    if (option==1)
        orderStatus(e);
    if (option == 2)
        showMenuForPersonAndCompany();

}*/

void orderStatus(int e) {

    OrderTracking order;
    if (e == 1)
    {
        cout << "Order en progreso..." << endl;
        order.updateStatus(OrderTracking::OrderStatus::IN_PROGRESS);

    }
    else if (e == 2) {
        cout << "Orden cancelada..." << endl;
        order.updateStatus(OrderTracking::OrderStatus::CANCELED);
    }
    else if (e == 3) {
        cout << "Orden pendiente..." << endl;
        order.updateStatus(OrderTracking::OrderStatus::PENDING);
    }
    else if (e == 4) {
        cout << "Orden entregada..." << endl;
        order.updateStatus(OrderTracking::OrderStatus::DELIVERED);
    }


}
void showMenuForPersonAndCompany(Lista<Product*>& products, Cola<int>& sumaPesos) {
   
    int option, n, integer = 0;
    int NUM=0, id;
    string name, dropPoint, pickUpPoint;
    int idProduct;
    float height, width, weight, value, distance = 0;
    float price = 0;
    string type = "", e;
    int idIngresado;

    Shipping shipping;
    VehicleType vehicletype;
    Ticket* ticket = new Ticket();

    cout << "1. Realizar nuevo pedido " << endl;
    cout << "2. Estado de mi pedido " << endl;
    cin >> option;
    int sumaPesoPedido = 0;

    switch (option)
    {
    case 1:
        
        cout << "Pedido " << integer + 1 << ": "; integer++;
        cout << endl;
        idProduct = integer;
        cout << "Ingresa el lugar de recojo: ";
        cin >> pickUpPoint;
        cout << "Ingresa el lugar de entrega: ";
        cin >> dropPoint;
        cout << "Ingresa la distancia del punto de origen al destino en kilometros:  ";
        cin >> distance;
        cout << "Ingresa la cantidad de productos a transportar: ";
        cin >> n;



        //iterador de productos
        for (int i = 0; i < n; i++)
        {
            id = i + 1;

            cout << "Ingresa el nombre del producto " << i + 1 << ": ";
            cin >> name;
            cout << "Ingresa la altura del producto " << i + 1 << " en centimetros: ";
            cin >> height;
            cout << "Ingresa el ancho del producto " << i + 1 << " en centimetros: ";
            cin >> width;
            cout << "Ingresa el peso del producto " << i + 1 << " en kilogramos: ";
            cin >> weight;
            cout << "Ingresa el valor del producto " << i + 1 << " en soles: S/.";
            cin >> value;
            cout << "Producto registrado exitosamente..." << endl;
            sumaPesoPedido += weight;
            products.agregaPos(new Product(name, id, width, height, weight, value), products.longitud());
        }
        sumaPesos.encolar(sumaPesoPedido);
        system("cls");

        price = shipping.calculatePrice(sumaPesoPedido, distance);
        type = vehicletype.calculateType(sumaPesoPedido);
        cout << "Tipo de vehiculo asignado por peso: " << type << endl;
        cout << "Precio estimado por peso y distancia: S/." << price << endl;
        cout << "Sí: Empezar con el pedido / No: Cancelar pedido (s/n):  ";
        cin >> e;
        if (e == "s") {
            NUM = 1;
            cout << endl;
            cout << "El pedido se recogera en " << pickUpPoint << " y se dejara en " << dropPoint << ". "<<endl;
            ticket->showTicketInfo(name, id, idProduct, price, type);
            cout << "Presiona una tecla para volver al menu principal" << endl;
            cout << "----------------------------------------------------" << endl;
            _getch();
            system("cls");
            showMenuForPersonAndCompany(products, sumaPesos);
        }
        else if (e == "n") {
            NUM = 2;
            system("cls");
            cout << "----------------------------------------------------"<<endl;
            showMenuForPersonAndCompany(products, sumaPesos);
        }
        orderStatus(NUM);
        break;

    }

    
}



void showMenuForDrivers(Lista<Driver*>& drivers) {

    int option, n;
    cout << "1. Lista de ordenes " << endl;
    cout << "2. Historial de mis viajes " << endl;
    cout << "3. Orden realizada " << endl;
    cin >> option;
    switch (option)
    {

    case 1:
        /*listar ?rdenes*/
        cout << "Ordenes encargadas: " << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {

        }
        break;
    case 2:
        break;
    case 3:
        /*Comparar si el id ingresado coincide con el id de alguna orden*/
        cout << "Ingresa el id de la orden realizada: ";

    default:
        break;
    }

}


void LogIn(Lista<User*>& users, Lista<Product*>& products, Cola<int>& sumaPesos) {
    int option2;
    string email, password;
    bool correctPassword = false;
    cout << "Ingresa tu correo electr?nico: ";
    cin >> email;

    bool cuentaEncontrada = false;
    for (uint i = 0; i < users.longitud(); i++) {
        User* user = users.obtenerPos(i);
        if (email == user->getEmail()) {
            cuentaEncontrada = true;
            cout << "¡Cuenta encontrada!" << endl;
            cout << "Ingresa tu contrasenia: ";
            cin >> password;
            if (password == user->getPassword()) {
                correctPassword = true;
                cout << "Bienvenido de vuelta " << user->getName() << endl;
                if (user->getUserType() != "Conductor") {
                    showMenuForPersonAndCompany(products, sumaPesos);
                    cin >> option2;
                }
                break;
            } else {
                cout << "Contrasenia incorrecta" << endl;
                cout << "Dirigiendote al menu principal..." << endl;
                break;
            }
        }
    }

    if (!cuentaEncontrada) {
        cout << "No hay ninguna cuenta registrada con ese correo electronico" << endl;
    }
}



void handleMenuSelection(Lista<User*>& users, Lista<Product*>& products, Lista<Order*>& order, Cola<int>& sumaPesos) {
    int option;
    cout << "Ingrese su opcion: ";
    cin >> option;

    switch (option) {
    case 1:
        system("cls");
        registerUser(users);
        break;
    case 2:
        system("cls");
        LogIn(users, products, sumaPesos);
        break;
    case 3:
        system("cls");
        if (users.longitud() != 0) {
            showUsers(users);
        }
        else {
            cout << endl;
            cout << "                                      --- --- --- --- --- --- --- " << endl;
            cout << "                                      No hay usuarios registrados" << endl;
            cout << "                                      --- --- --- --- --- --- --- " << endl;
        }
        break;
    case 4:
        cout << "Saliendo del programa..." << endl;
        return; // Caso base de la recursión
    default:
        cout << "Opcion inválida. Por favor, ingrese una opcion valida." << endl;
        break;
    }

    showMenu(); // Llamada recursiva para mostrar el menú nuevamente
    handleMenuSelection(users, products, order, sumaPesos); // Llamada recursiva para manejar la selección del usuario
}


int main()
{

    Lista<User*> users;
    Lista<Product*> products;
    Lista<Order*> order;
    Cola<int> sumaPesos;

    showMenu(); // Mostrar el menú inicial
    handleMenuSelection(users, products, order, sumaPesos); // Manejar la selección del usuario

    return 0;



}
