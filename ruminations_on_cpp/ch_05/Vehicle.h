#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <iostream>

class Vehicle {

public:
	virtual void whoami() const = 0;
	virtual Vehicle* copy() const = 0;
	virtual ~Vehicle() {};
	
};

class RoadVehicle : public Vehicle {
	
public:
    RoadVehicle() {}
    ~RoadVehicle() {}
	void whoami() const;
	Vehicle* copy() const;
};

class AutoVehicle : public Vehicle {
public:
    AutoVehicle() {}
    ~AutoVehicle() {}
	void whoami() const;
	Vehicle* copy() const;
};

class Aircraft : public Vehicle {
public:
    Aircraft() {}
    ~Aircraft() {}
	void whoami() const;
	Vehicle* copy() const;
};

class Helicopter : public Vehicle {
public:
    Helicopter() {}
    ~Helicopter() {}
	void whoami() const;
	Vehicle* copy() const;
};
#endif
