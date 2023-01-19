#include <systemc.h>
#include "CabinDoor.h"
#include "CabinSensor.h"

#define STTBITS 3
#define PERSON_DELAY 30 // cho 30 giay doi
#define SAFETY_DELAY 5

enum CabinStatus
{
	idle,		// ranh
	pre_ready,	// dang dong cua
	ready,		// san sang dua len cap
	running,	// dang di tren cap treo/banh rang
	dropoff		// tra khach
};

SC_MODULE(Cabin) {
	CabinDoor* door;
	sc_signal<DoorStatus> door_stt;
	
	CabinSensor* sensor;
	sc_signal<bool> sig_all, sig_people, sig_safety;

	CabinStatus status = idle;
	sc_uint<32> timer = 0;
	sc_clock clk;


	SC_CTOR(Cabin)
		:clk("clk", 1, SC_US) // 1 MHz clock
	{
		sensor = new CabinSensor("sensor");
		sensor->clk(clk);
		sensor->out(sig_all);
		sensor->people_out(sig_people);
		sensor->safety_out(sig_safety);

		door = new CabinDoor("door");
		door->out(door_stt);

		SC_THREAD(cabin_main);
	};

	~Cabin();

	void cabin_main();
	void closeDoor();
	void openDoor();
	void updateStatus(CabinStatus stt);
	CabinStatus getStatus();
};
