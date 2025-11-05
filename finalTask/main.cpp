#include <iostream>
#include "Base.h"
#include "Bus.h"
#include "Truck.h"

int main() {
    Base::printStatus();

    Bus bus(20, 30, 20, 60);
    Truck truck(5, 10, 10, 60);

    std::cout << "\nBus arrives...\n";
    bus.arrive();
    Base::printStatus();

    std::cout << "\nTruck arrives...\n";
    truck.arrive();
    Base::printStatus();

    std::cout << "\nBus tries to leave...\n";
    if (bus.leave())
        std::cout << "Bus left.\n";
    else
        std::cout << "Bus cannot leave.\n";
    Base::printStatus();

    std::cout << "\nTruck tries to leave...\n";
    if (truck.leave())
        std::cout << "Truck left.\n";
    else
        std::cout << "Truck cannot leave.\n";
    Base::printStatus();

    return 0;
}
