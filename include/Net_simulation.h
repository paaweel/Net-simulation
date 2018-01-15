/*
 * Net_simulation.h
 *
 *  Created on: Jan 13, 2018
 *      Author: franek
 */

#ifndef NET_SIMULATION_H_
#define NET_SIMULATION_H_

#include <map>
#include <utility>
#include "types.h"

class IPackageDepot {
public:
	virtual void push(Package) = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual Package* view() = 0;
}; // IPackageDepot

class IPackageQueue : public IPackageDepot {
public:
	virtual Package pop() = 0;
	virtual QueueType getQueueType() = 0;
}; // IPackageQueue

class IPackageReceiver {
public:
	virtual void receivePackage(Package) = 0;
	virtual Package* viewDepot() = 0;
	virtual ReceiverType getReceiverType() = 0;
	virtual ElementID getID() = 0;
}; // IPackageReceiver

#endif /* NET_SIMULATION_H_ */
