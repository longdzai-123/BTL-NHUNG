#include "CabinSensor.h"

bool CabinSensor::checkPeople() {
	bool result = people_in.read();
	people_out.write(result);
	return result;
}

bool CabinSensor::checkSafety() {
	bool result = safety_in.read();
	safety_out.write(result);
	return result;
}

bool CabinSensor::checkAll() {
	bool result = checkPeople() && checkSafety();
	out.write(result);
	return result;
}

void CabinSensor::sensor_main() {
	while (true)
		checkAll();
}