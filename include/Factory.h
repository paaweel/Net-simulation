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

typedef Collection<Ramp*> RampCollection;
typedef Collection<Worker*> WorkerCollection;
typedef Collection<StoreHouse*> StorehouseCollection;

// END COLLECTION TEMPLATE


class Factory
{
private:
	RampCollection ramps;
	WorkerCollection workers;
	StorehouseCollection storehouses;

public:
	Factory(RampCollection r, WorkerCollection w, StorehouseCollection s) :	ramps {r}, workers {w},	storehouses {s} {

	}
	std::list<Ramp*> getRamps() {return ramps.group;};
	void addRamp(Ramp*);
	void removeRamp(ElementID);

	std::list<Worker*> getWorkers() {return workers.group;};
	void addWorker(Worker*);
	void removeWorker(ElementID);

	std::list<StoreHouse*> getStorehouses() {return storehouses.group;};
	void addStorehouse(StoreHouse*);
	void removeStorehouse(ElementID);

	bool isConsistent();
};

#endif /* FACTORY_H_ */
