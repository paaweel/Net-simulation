/*
 * Factory.cpp
 *
 *  Created on: 13 sty 2018
 *      Author: Mateusz
 */

#include "../include/Factory.h"

void Factory::addRamp(Ramp _ramp)
{
	ramps.group.push_back(_ramp);
}

void Factory::removeRamp(ElementID _id)
{
	ramps.removeById(ramps.group, _id);
}

void Factory::addWorker(Worker _worker)
{
	workers.group.push_back(_worker);
}

void Factory::removeWorker(ElementID _id)
{
	workers.removeById(workers.group,_id);
}

void Factory::addStorehouse(StoreHouse _storehouse)
{
	storehouses.group.push_back(_storehouse);
}

void Factory::removeStorehouse(ElementID _id)
{
	storehouses.removeById(storehouses.group,_id);
}

bool Factory::isConsistent()
{
	auto itRamps = std::find_if(ramps.group.begin(), ramps.group.end(), [](const Ramp &cls) { return ( cls.receiverPreferences.hasEmptyConnection() ); } );

	auto itWorkers = std::find_if(workers.group.begin(), workers.group.end(), [](const Ramp &cls) { return ( cls.receiverPreferences.hasEmptyConnection() ); } );

	if( (itRamps == ramps.group.end()) && (itWorkers == workers.group.end()) ) return true;
	else return false;

}
