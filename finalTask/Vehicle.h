#pragma once
#include "Base.h"

class Vehicle {
protected:
    double petrol;
    double tank_volume;

public:
    Vehicle(double petrol_amount, double tank_volume);

    double getTankVolume();
    double getPetrolAmount();

    virtual void arrive();
    virtual bool leave();
};
