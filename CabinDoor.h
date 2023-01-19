#pragma once
#include <systemc.h>
enum DoorStatus
{
	closed,
	opened,
	//moving, // cua dang di chuyen
};
SC_MODULE(CabinDoor) {
	sc_out<DoorStatus> out;
	DoorStatus status;

	SC_CTOR(CabinDoor) {
		status = closed;
		out.write(status);
	}
	void open();
	void close();
};
