#include "CabinDoor.h"

void CabinDoor::open() {
	if (status == closed)
	{
		status = opened;
		out.write(status);
	}
}

void CabinDoor::close() {
	if (status == opened)
	{
		status = closed;
		out.write(status);
	}
}