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
	queue = queue_;
}

void Worker::receivePackage(Package package_)
{
	queue->push(package_);
	//if (queue->getQueueType == QueueType::FIFO)
		//currentlyProcessedPackage.push_back(package_) ??
}

Package* Worker::viewDepot()
{
	//?
}

void Worker::doWork()
{
	//?
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