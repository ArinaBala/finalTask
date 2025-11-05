#include "Vehicle.h"

Vehicle::Vehicle(double petrol_amount, double tank_volume): petrol(petrol_amount), tank_volume(tank_volume) {}

double Vehicle::getTankVolume() {
    return tank_volume;
}

double Vehicle::getPetrolAmount() {
    return petrol;
}

void Vehicle::arrive() {
    Base::vehicles_on_base++;
    Base::people_on_base++; 
}

bool Vehicle::leave() {
    double need = tank_volume - petrol;

    if (need < 0) need = 0;
    if (Base::petrol_on_base < need) return false;
    if (Base::people_on_base < 1) return false;

    Base::petrol_on_base -= need;
    petrol = tank_volume;

    Base::vehicles_on_base--;
    Base::people_on_base--;

    return true;
}
