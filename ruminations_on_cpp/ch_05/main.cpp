#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "VehicleSurrogate.h"

int main() {
	VehicleSurrogate parking_lot[4];
	int num = 0;

	RoadVehicle r;
	AutoVehicle a;
	Aircraft air;
	Helicopter h;
	parking_lot[num++] = (VehicleSurrogate(r));
	parking_lot[num++] = (a);
	parking_lot[num++] = (air);
	parking_lot[num++] = (h);

	for (int i = 0; i < num; ++i) {
		parking_lot[i].whoami();
	}

}
