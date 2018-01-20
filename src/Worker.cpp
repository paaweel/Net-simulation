/*
 * Worker.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: franek
 */

#include <PackageQueue.h>
#include "Worker.h"

Worker::Worker(ElementID id_, TimeOffset processingDuration_, QueueType type, std::shared_ptr<IPackageQueue> queue_)
{
	id = id_;
	processingDuration = processingDuration_;
	if (queue_ != nullptr)
		queue = queue_;
	else {
		auto queue__ = std::make_shared<PackageQueue>(type);
		queue = queue__;
	}
}

void Worker::receivePackage(Package package_)
{
	queue->push(package_);
}

std::vector<Package> Worker::viewDepot()
{
	//?
}

void Worker::doWork()
{
    if (!queue->empty()) {
		addToBuffer(queue->pop());
	}
}

TimeOffset Worker::getProcessingDuration()
{
	return processingDuration;
}

Time Worker::getPackageProcessingStartTime()
{
	return packageProcessingStartTime;
}

ReceiverType Worker::getReceiverType()
{
	return ReceiverType::WORKER;
}

ElementID Worker::getID() const
{
	return id;
}
/*
void sendPackage()
{
	
}

std::vector<Package> viewSendingBuffer()
{
	
}
*/