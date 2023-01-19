#pragma once
#include <systemc.h>
#include "Cabin.h"
#include <queue>

//enum QueueStatus
//{
//	empty,
//};

SC_MODULE(CabinQueue)
{
	std::queue<Cabin> q;

	SC_CTOR(CabinQueue){
		//TODO: Constructor CabinQueue
	};
	void enqueue(Cabin c);
	void dequeue();
	void checkStatus();
};

