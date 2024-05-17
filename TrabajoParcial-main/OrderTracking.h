#pragma once
#include <iostream>
#include <string>

class OrderTracking {

public:
    enum class OrderStatus {
        PENDING,
        IN_PROGRESS,
        DELIVERED,
        CANCELED
    };

    OrderTracking() : status(OrderStatus::PENDING) {}

    void updateStatus(OrderStatus newStatus) {
        status = newStatus;
    }

    string getStatusString() {
        switch (status) {
        case OrderStatus::PENDING:
            return "Pendiente";
        case OrderStatus::IN_PROGRESS:
            return "En progreso";
        case OrderStatus::DELIVERED:
            return "Entregado";
        case OrderStatus::CANCELED:
            return "Cancelado";
        default:
            return "Desconocido";
        }
    }

private:
    OrderStatus status;
};

