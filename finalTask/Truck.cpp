#include "Truck.h"

Truck::Truck(double load, double max_load, double petrol, double max_petrol): Vehicle(petrol, max_petrol), load(load), max_load(max_load) {}

double Truck::getCurrentLoad() { return load; }
double Truck::getMaxLoad() { return max_load; }

void Truck::arrive() {
    Base::vehicles_on_base++;
    Base::people_on_base++;
    Base::goods_on_base += load;
    if (Base::goods_on_base < 0) Base::goods_on_base = 0;
    load = 0;
}

bool Truck::leave() {
    double need = tank_volume - petrol;
    if (need < 0) need = 0;

    if (Base::petrol_on_base < need) return false;
    if (Base::people_on_base < 1) return false;

    Base::petrol_on_base -= need;
    petrol = tank_volume;

    double can_take = max_load;
    if (Base::goods_on_base < can_take)
        can_take = Base::goods_on_base;

    if (can_take < 0) can_take = 0;

    Base::goods_on_base -= can_take;
    load = can_take;

    Base::vehicles_on_base--;
    Base::people_on_base--;

    return true;
}
