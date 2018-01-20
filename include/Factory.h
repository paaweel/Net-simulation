/*
 * Factory.h
 *
 *  Created on: 13 sty 2018
 *      Author: Mateusz
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include<list>
#include<algorithm>
#include <iostream>
#include"ramp.h"
#include"Worker.h"
#include"StoreHouse.h"

// BEGIN COLLECTION TEMPLATE

template<typename T>
class Collection
{
public:
	std::list<T> group;

	Collection() {}
	Collection(std::list<T> _group) : group(_group) {};


	typename std::list<T>::iterator findById(std::list<T> &l, ElementID id)
	{
		return std::find_if(l.begin(), l.end(), [id](const T& cls){	return (cls->getID() == id);} );
	};

	void removeById(std::list<T>&l, ElementID id)
	{
		auto it = findById(l, id);

		bool wasFound = (it != l.end());
		if (wasFound)
		{
			l.erase(it);
		}
	};


};

typedef Collection<std::shared_ptr<Ramp>> RampCollection;
typedef Collection<std::shared_ptr<Worker>> WorkerCollection;
typedef Collection<std::shared_ptr<StoreHouse>> StorehouseCollection;

// END COLLECTION TEMPLATE


class Factory
{
private:
	RampCollection ramps;
	WorkerCollection workers;
	StorehouseCollection storehouses;

public:
	Factory() :	ramps(), workers(),	storehouses() {}
	Factory(RampCollection r, WorkerCollection w, StorehouseCollection s)
			:	ramps(r), workers(w),	storehouses(s) {}
	std::list<std::shared_ptr<Ramp>> getRamps() {return ramps.group;};
	void addRamp(ElementID _id, TimeOffset _to);
	void removeRamp(ElementID);

	std::list<std::shared_ptr<Worker>> getWorkers() {return workers.group;};
	void addWorker(ElementID id_, TimeOffset processingDuration_, QueueType = QueueType::LIFO,
				   std::shared_ptr<IPackageQueue> queue_ = nullptr);
	void removeWorker(ElementID);

	std::list<std::shared_ptr<StoreHouse>> getStorehouses() {return storehouses.group;};
	void addStorehouse(ElementID _id);
	void removeStorehouse(ElementID);
	void addLink(PackageSender *sender, IPackageReceiver* receiver, double prob = 0);

	//bool isConsistent();
};

#endif /* FACTORY_H_ */
