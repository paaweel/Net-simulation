/*
 * Worker.h
 *
 *  Created on: Jan 13, 2018
 *      Author: franek
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <vector>
#include "Net_simulation.h"
#include "types.h"
#include "PackageSender.h"

class Worker : public IPackageReceiver, public PackageSender {
private:
	ElementID id;
	TimeOffset processingDuration;
	Time packageProcessingStartTime;
	IPackageQueue* queue;
	std::vector<Package> currentlyProcessedPackage;
public:
	Worker(ElementID, TimeOffset, IPackageQueue* = nullptr);
	void receivePackage(Package) override;
	std::vector<Package> viewDepot() override;
	void doWork();
	TimeOffset getProcessingDuration();
	Time getPackageProcessingStartTime();
	ReceiverType getReceiverType() override;
	ElementID getID() const override;
};



#endif /* WORKER_H_ */
