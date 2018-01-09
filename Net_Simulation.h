#ifndef NET_SIMULATION_H_
#define NET_SIMULATION_H_

#include "types.h"
#include <map>
#include <utility>

class IPackageDepot {
public:
	virtual void push(Package package) = 0;
	virtual bool empty() = 0;
	virtual bool size() = 0;
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

class ReceiverPreferences {
private:
	std::map<IPackageReceiver*, double> probabilities;
public:
	std::map<IPackageReceiver*, double> getPreferences();
	void setPreferences(std::map<IPackageReceiver*, double>);
	void addReceiver(IPackageReceiver*);
	void addReceiverWithProbability(IPackageReceiver*, double);
	void removeReceiver(IPackageReceiver*);
	IPackageReceiver* drawReceiver(double);
	std::pair<IPackageReceiver*, double>* view();
}; // ReceiverPreferences

#endif /* NET_SIMULATION_H_ */
