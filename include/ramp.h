//
// Created by pawel on 12.01.2018.
//

#ifndef NET_SIMULATION_RAMP_H
#define NET_SIMULATION_RAMP_H


#include "types.h"
#include "PackageSender.h"


class Ramp : public PackageSender{
private:
    ElementID id;
    TimeOffset deliveryInterval;
public:
    Ramp(ElementID _id, TimeOffset _to) {
        id = _id;
        deliveryInterval = _to;
    }
    void deliverGoods(Time) {
        sendPackage();
    }
    TimeOffset getDeliveryInterval() {
        return deliveryInterval;
    }

    ElementID getId() {return id;};
};


#endif //NET_SIMULATION_RAMP_H
