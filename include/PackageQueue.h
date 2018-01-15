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
	//std::function<Package()>
    //temporary solution
    std::function<Package(std::deque<Package>&)>_popFunction;
public:
    explicit PackageQueue(QueueType);
	void push(Package) override;
	Package pop() override;
	Package* view() override;
	QueueType getQueueType() override;
	bool empty() override ;
	int size() override;
};



#endif /* PACKAGEQUEUE_H_ */
