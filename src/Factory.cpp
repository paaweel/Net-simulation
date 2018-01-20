/*
 * Factory.cpp
 *
 *  Created on: 13 sty 2018
 *      Author: Mateusz
 */

#include "../include/Factory.h"

void Factory::addRamp(ElementID _id, TimeOffset _to)
{
	auto _ramp = std::make_shared<Ramp> (_id, _to);
	ramps.group.push_back(_ramp);
}

void Factory::removeRamp(ElementID _id)
{
	ramps.removeById(ramps.group, _id);
}

void Factory::addWorker(ElementID id_, TimeOffset processingDuration_,QueueType type, std::shared_ptr<IPackageQueue> queue_)
{
    auto _worker = std::make_shared<Worker> (id_, processingDuration_, type, queue_);
	workers.group.push_back(_worker);
}

void Factory::removeWorker(ElementID _id)
{
	workers.removeById(workers.group,_id);
}

void Factory::addStorehouse(ElementID _id)
{
	auto _storehouse = std::make_shared<StoreHouse> (_id);
	storehouses.group.push_back(_storehouse);
}

void Factory::removeStorehouse(ElementID _id)
{
	storehouses.removeById(storehouses.group,_id);
}
/*
bool Factory::isConsistent()
{
	auto itRamps = std::find_if(ramps.group.begin(), ramps.group.end(), [](const Ramp* cls) { return ( cls->receiverPreferences.hasEmptyConnection() ); } );

	auto itWorkers = std::find_if(workers.group.begin(), workers.group.end(), [](const Worker* cls) { return ( cls->receiverPreferences.hasEmptyConnection() ); } );

	return ( (itRamps == ramps.group.end()) && (itWorkers == workers.group.end()) );
}
*/
void Factory::addLink(PackageSender *sender, IPackageReceiver* receiver, double prob) {
	if (prob != 0)
		sender->receiverPreferences.addReceiver(receiver, prob);
	else
		sender->receiverPreferences.addReceiver(receiver);

}
