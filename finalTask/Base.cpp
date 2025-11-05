#include "Base.h"

int Base::people_on_base = 50;
int Base::vehicles_on_base = 10;
double Base::petrol_on_base = 500;
double Base::goods_on_base = 20;

void Base::printStatus() {
    std::cout << "\nBASE STATUS\n";
    std::cout << "People: " << people_on_base << "\n";
    std::cout << "Vehicles: " << vehicles_on_base << "\n";
    std::cout << "Petrol: " << petrol_on_base << " L\n";
    std::cout << "Goods: " << goods_on_base << " tons\n";
}
