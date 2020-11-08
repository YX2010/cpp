#ifndef _VEHICLE_SURROGATE_H
#define _VEHICLE_SURROGATE_H

#include <iostream>

class Vehicle;
class VehicleSurrogate {

public:
	VehicleSurrogate();
	VehicleSurrogate(const Vehicle&);
	~VehicleSurrogate();
	VehicleSurrogate(const VehicleSurrogate&);
	VehicleSurrogate& operator=(const VehicleSurrogate&);
	void whoami() const;

private:
	Vehicle* vp;

};

#endif
