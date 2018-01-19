//
// Created by pawel on 12.01.2018.
//

#ifndef NET_SIMULATION_STOREHOUSE_H
#define NET_SIMULATION_STOREHOUSE_H

#include "Net_Simulation.h"

class StoreHouse : public IPackageReceiver {
private:
    ElementID id;
    std::vector<Package> packageDepot;
public:
    explicit StoreHouse(ElementID _id) {
        id = _id;
    }
    void receivePackage(Package p) override {
        packageDepot.emplace_back(p);
    }
    std::vector<Package> viewDepot() override {
        return packageDepot;
    }
    ReceiverType getReceiverType() override {
        return ReceiverType::STOREHOUSE;
    }
    ElementID getID() const override {
        return id;
    }
};



#endif //NET_SIMULATION_STOREHOUSE_H
