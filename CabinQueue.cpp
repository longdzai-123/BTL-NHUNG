#include "CabinQueue.h"

void CabinQueue::enqueue(Cabin c){
	q.push(c);
}

void CabinQueue::dequeue(){
	q.pop();
}

void CabinQueue::checkStatus(){
	// TODO
}