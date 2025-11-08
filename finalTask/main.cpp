#include <iostream>
#include "Base.h"
#include "Bus.h"
#include "Truck.h"

int main() {
    Base::printStatus();

    Bus bus(20, 30, 20, 60);
    Truck truck(5, 10, 10, 60);

    cout << "\nBus arrives...\n";
    bus.arrive();
    Base::printStatus();

    cout << "\nTruck arrives...\n";
    truck.arrive();
    Base::printStatus();

    cout << "\nBus tries to leave...\n";
    if (bus.leave())
        cout << "Bus left.\n";
    else
        cout << "Bus cannot leave.\n";
    Base::printStatus();

    std::cout << "\nTruck tries to leave...\n";
    if (truck.leave())
        cout << "Truck left.\n";
    else
        cout << "Truck cannot leave.\n";
    Base::printStatus();

    return 0;
}
