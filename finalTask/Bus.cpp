#include "Bus.h"

Bus::Bus(int people, int max_people, double petrol, double max_petrol): Vehicle(petrol, max_petrol), people(people), max_people(max_people) {}

int Bus::getPeopleCount() { return people; }
int Bus::getMaxPeople() { return max_people; }

void Bus::arrive() {
    Base::vehicles_on_base++;
    Base::people_on_base += (people + 1);
    if (Base::people_on_base < 0) Base::people_on_base = 0;
    people = 0;
}

bool Bus::leave() {
    double need = tank_volume - petrol;
    if (need < 0) need = 0;

    if (Base::petrol_on_base < need) return false;
    if (Base::people_on_base < 1) return false;

    Base::petrol_on_base -= need;
    petrol = tank_volume;

    int can_take = max_people;
    if (Base::people_on_base - 1 < can_take)
        can_take = Base::people_on_base - 1;

    if (can_take < 0) can_take = 0;

    Base::people_on_base -= (can_take + 1);
    people = can_take;

    Base::vehicles_on_base--;

    return true;
}
