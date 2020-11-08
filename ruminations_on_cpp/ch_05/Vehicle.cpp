#include <iostream>
#include "Vehicle.h"

void
RoadVehicle::whoami() const {
	std::cout << "RoadVehicle" << std::endl;
}

Vehicle*
RoadVehicle::copy() const {
    return new RoadVehicle(*this);
}

void
AutoVehicle::whoami() const {
	std::cout << "AutoVehicle" << std::endl;
}

Vehicle*
AutoVehicle::copy() const {
	return new AutoVehicle(*this);
}


void
Aircraft::whoami() const {
	std::cout << "Aircraft" << std::endl;
}
Vehicle*
Aircraft::copy() const {
	return new Aircraft(*this);
}

void
Helicopter::whoami() const {
	std::cout << "Helicopter" << std::endl;
}
Vehicle*
Helicopter::copy() const {
	return new Helicopter(*this);
}
