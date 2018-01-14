//
// Created by pawel on 12.01.2018.
//

#ifndef NET_SIMULATION_RECEIVERPREFERENCES_H
#define NET_SIMULATION_RECEIVERPREFERENCES_H

#include <random>
#include "Net_Simulation.h"


class ReceiverPreferences {
private:
    std::map<IPackageReceiver*, double> probabilities;
    std::mt19937 gen;
public:
    ReceiverPreferences() : gen(std::random_device()()){}
    std::map<IPackageReceiver*, double> getPreferences() {
        return probabilities;
    }
    void setPreferences(std::map<IPackageReceiver*, double>);
    void addReceiver(IPackageReceiver*);
    void addReceiverWithProbability(IPackageReceiver*, double);
    void removeReceiver(IPackageReceiver*);
    IPackageReceiver* drawReceiver(); //parameter double is not required, yet
    //returning vector, instead of an array
    std::vector<std::pair<IPackageReceiver*, double>> view();

    bool hasEmptyConnection();

}; // ReceiverPreferences


#endif //NET_SIMULATION_RECEIVERPREFERENCES_H
