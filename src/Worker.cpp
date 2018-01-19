/*
 * Worker.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: franek
 */

#include "Worker.h"

Worker::Worker(ElementID id_, TimeOffset processingDuration_, IPackageQueue* queue_)
{
	id = id_;
	processingDuration = processingDuration_;
	if (queue_ != nullptr)
		queue = queue_;
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