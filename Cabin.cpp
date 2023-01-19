#include "Cabin.h"

Cabin::~Cabin() {
	delete sensor;
	delete door;
}

void Cabin::cabin_main() {
	wait(); // doi 1 chu ky xung clock
	while (true) {
		switch (status)
		{
		case idle:
			// xu ly trong trang thai cho
			// Doc cam bien, ko co nguoi thi reset timer
			timer++;
			if (sig_people.read() == false) {
				timer = 0;
			}
			else if (timer > PERSON_DELAY * 1000000u) {
				updateStatus(pre_ready);
				timer = 0;
			}
			break;
		case pre_ready:
			// xu ly trong trang thai dang dong cua
			// neu co nguoi qua lai thi reset timer, mo cua
			timer++;
			if(sig_people.read() == false){
				timer = 0;
				updateStatus(idle);
			}
			if (sig_safety.read() == false) {
				timer = 0;
				openDoor();
			}
			else if (timer > SAFETY_DELAY * 1000000u) {
				closeDoor();
				timer = 0;
				if (door_stt.read() == closed)
				{
					updateStatus(ready);
					// TODO: enqueue
				}
			}
			break;
		case ready:
			// TODO: xu ly trong trang thai san sang: cho tin hieu dua len cap de xu ly
			// nhan tin hieu dua len cap
			// chuyen sang running
			break;
		case running:
			// TODO: xu ly trong trang thai running: cho doi tin hieu ve tram de xu ly
			// Nhan tin hieu
			// mo cua
			// chuyen sang dropoff
			break;
		case dropoff:
			// TODO: xu ly trong trang thai tra khach
			// nhan tin hieu khong con khach
			// chuyen sang idle
			if (sensor->checkPeople() == false) {
				updateStatus(idle);
			}
			break;
		default:
			break;
		}
		wait();
	}
}

void Cabin::closeDoor() {
	door->close();
	cout << "cabin dong cua\n";
}

void Cabin::openDoor() {
	door->open();
	cout << "cabin mo cua\n";
}

void Cabin::updateStatus(CabinStatus stt) {
	status = stt;
}

CabinStatus Cabin::getStatus() {
	return status;
}