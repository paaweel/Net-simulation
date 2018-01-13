/*
 * PackageQueue.h
 *
 *  Created on: Jan 13, 2018
 *      Author: franek
 */

#ifndef PACKAGEQUEUE_H_
#define PACKAGEQUEUE_H_

#include "Net_simulation.h"
#include <deque>
#include <functional>

class PackageQueue : public IPackageQueue {
private:
	QueueType PackageQueueType; //?
	std::deque<Package> deque;
	std::function<Package()> _popFunction;
public:
	PackageQueue(QueueType);
	void push(Package);
	Package pop();
	Package* view();
	QueueType getQueueType();
	bool isEmpty();
	int size();
};



#endif /* PACKAGEQUEUE_H_ */
