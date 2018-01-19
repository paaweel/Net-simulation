//
// Created by pawel on 16.01.2018.
//

#ifndef NET_SIMULATION_SIMULATE_H
#define NET_SIMULATION_SIMULATE_H

#include <functional>
#include "Types.h"
#include "Factory.h"

//std::function(Factory&, TimeOffset) Have no idea what

void simulate(Factory & factory, TimeOffset timeOffset) {

    auto workers = factory.getWorkers();
    auto storeHouses = factory.getStorehouses();
    auto ramps = factory.getRamps();

    for(int i = 0; i < 20; ++i) {
        for (auto & r : ramps) {
            r->deliverGoods();
        }
        for(auto & w : workers) {
            w->doWork();
            w->sendPackage();
        }
        for(auto & s : storeHouses) {
            auto depot  = s->viewDepot();
            for (auto x : depot) {
                std::cout << x.getId() << " ";
            }
            std::cout << std::endl;
        }
    }
}

#endif //NET_SIMULATION_SIMULATE_H
