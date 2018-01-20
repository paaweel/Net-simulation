//
// Created by pawel on 16.01.2018.
//

#ifndef NET_SIMULATION_SIMULATE_H
#define NET_SIMULATION_SIMULATE_H

#include <functional>
#include <fstream>
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
    std::cout << std::endl;
    std::cout << std::endl;
    //THIS LINE IS REQUIRED
    //without it not all ids are showed
    //have no idea why
}
std::vector<int> getData(std::string line) {
    std::vector<int> data;
    std::string current;

    for ( auto x : line) {
        if ( x == 'w' || x == 'r' || x == 's' || x == 'l')  //is there a way to start a ranged for from a point?
            continue;
        else if (x != ';') {
            current.push_back(x);
        }
        else if (!current.empty()) {
            data.push_back(std::stoi(current));
            current.clear();
        }
    }
    return data;
}

bool load(Factory & factory, std::string path) {
    /*
     * format
     * w - worker
     * r - ramp
     * s - storehouse
     * node:
     *  r;1;2;  //r,w;  id;     timeoffset;
     *  s;1;    //s;    id;
     *
     *  link:
     *                  sender  receiver
     *  lws1;2; //l     w, r    w, s    sender_id   receiver_id
     */

    std::ifstream file;
    file.open(path);

    if (!file.is_open()) {
        std::cout << "sorry!\n";
        return false;
    }

    std::string line;
    std::vector<int> data;
    while ( std::getline (file, line) )
    {
        switch(line[0]) {
            case 'w':
                data = getData(line);
                factory.addWorker(data[0], data[1]);
                data.clear();
                break;
            case 'r':
                data = getData(line);
                factory.addRamp(data[0], data[1]);
                data.clear();
                break;
            case 's':
                data = getData(line);
                factory.addStorehouse(data[0]);
                data.clear();
                break;
            case 'l':
                auto workers = factory.getWorkerCollection();
                auto storeHouses = factory.getStorehouseCollection();
                auto ramps = factory.getRampCollection();
                data = getData(line);
                PackageSender* sender = nullptr;
                IPackageReceiver* receiver = nullptr;
                if (line[1] == 'r') {
                    sender = ramps.findById(data[0])->get();
                }
                else if (line[1] == 'w') {
                    sender = workers.findById(data[0])->get();
                }
                if (line[2] == 'w') {
                    receiver = workers.findById(data[1])->get();
                }
                else if (line[2] == 's'){
                    receiver = storeHouses.findById(data[1])->get();
                }
                if (sender != nullptr && receiver != nullptr) {
                    if (data.size() < 3)
                        factory.addLink(sender, receiver);
                    else
                        factory.addLink(sender, receiver, data[2]/100.0);
                }
                data.clear();
        }
    }

    file.close();
    return true;
}

#endif //NET_SIMULATION_SIMULATE_H
