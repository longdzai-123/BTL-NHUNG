#pragma once

#include <systemc.h>

SC_MODULE(CabinSensor) {

	sc_in<bool> clk, people_in, safety_in;
	sc_out<bool> out, people_out, safety_out;

	SC_CTOR(CabinSensor){
		out.write(false);
		people_out.write(false);
		safety_out.write(false);
		SC_THREAD(sensor_main, clk.pos());
	};
	void sensor_main();
	bool checkPeople();
	bool checkSafety();
	bool checkAll();
};
