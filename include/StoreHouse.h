//
// Created by pawel on 12.01.2018.
//

#ifndef NET_SIMULATION_STOREHOUSE_H
#define NET_SIMULATION_STOREHOUSE_H

#include "Net_Simulation.h"

class StoreHouse : public IPackageReceiver {
private:
    ElementID id;
    IPackageDepot* packageDepot;
public:
    StoreHouse(ElementID _id) {
        id = _id;
    }
    void receivePackage(Package) override {}
    Package* viewDepot() override {
        Package *p = new Package;
        return p;
    }
    ReceiverType getReceiverType() override {
        return ReceiverType::STOREHOUSE;
    }
    ElementID getID() override {
        return id;
    }
};



#endif //NET_SIMULATION_STOREHOUSE_H
