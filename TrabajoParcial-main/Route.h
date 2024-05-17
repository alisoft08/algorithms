#pragma once
#include <iostream>
using namespace std;
class Route
{
private:
    string origin, destination, routeType;
    double distance;
    float travelTime;

public:
    Route();
    ~Route();

    Route(string _origin, string _destination, string _routeType, double _distance, float _travelTime)
        : origin(_origin), destination(_destination), routeType(_routeType), distance(_distance), travelTime(_travelTime)
    {}

    void setOrigin(string _origin) {
        origin = _origin;
    }

    void setDestination(string _destination) {
        destination = _destination;
    }
    void setRouteType(string _routeType) {
        routeType = _routeType;
    }

    void setDistance(double _distance) {
        distance = _distance;
    }

    void setTravelTime(float _travelTime) {
        travelTime = _travelTime;
    }
    string getOrigin() {
        return origin;
    }

    string getDestination() {
        return destination;
    }

    string getRouteType() {
        return routeType;
    }

    double getDistance() {
        return distance;
    }

    float getTravelTime() {
        return travelTime;
    }

};

