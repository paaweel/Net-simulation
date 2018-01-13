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

void Worker::receivePackage(Package)
{
	//currentlyProcessedPackage.push_back(Package); // ?
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

ElementID Worker::getID()
{
	return id;
}
