#include <iostream>
#include "VehicleSurrogate.h"
#include "Vehicle.h"

VehicleSurrogate::VehicleSurrogate() : vp(0) {
}

VehicleSurrogate::
VehicleSurrogate(const Vehicle& v) : vp(v.copy()) {

} 

VehicleSurrogate::~VehicleSurrogate() {
	delete vp;
}

VehicleSurrogate::
VehicleSurrogate(const VehicleSurrogate& v) 
	: vp (v.vp ? v.vp->copy() : 0) { }

VehicleSurrogate&
VehicleSurrogate::operator=(const VehicleSurrogate& v) {
	if (this != &v) {
		delete vp;
		vp = v.vp ? v.vp->copy() : 0;
	}
	return *this;
}


void
VehicleSurrogate::whoami() const {
	if (vp == nullptr) {
		std::cout << "empty" << std::endl;
	} else {
		vp->whoami();
	}
}
