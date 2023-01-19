#include <systemc.h>
#include "Cabin.h"

int sc_main(int argc, char* argv[]) {
	Cabin c("c"); // test thu module cabin xem chay dc ko
	c.openDoor();
	c.closeDoor();

	//sc_start(); // mo phong
	//if (not sc_end_of_simulation_invoked()) {
	//	cout << "Simulation stopped without explicit sc_stop()" << endl;
	//	sc_stop();
	//}
	return(0);
}
