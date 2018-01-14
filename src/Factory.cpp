/*
 * Factory.cpp
 *
 *  Created on: 13 sty 2018
 *      Author: Mateusz
 */

#include "Factory.h"

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
