//
// Created by pawel on 12.01.2018.
//

#ifndef NET_SIMULATION_PACKAGESENDER_H
#define NET_SIMULATION_PACKAGESENDER_H

#include <vector>
#include <memory>
#include "Net_Simulation.h"
#include "ReceiverPreferences.h"

class PackageSender {
private:
    std::vector<Package> sendingBuffer;
public:
    ReceiverPreferences receiverPreferences;

    //PackageSender(ElementID); //what's the purpose of this constructor?
    void sendPackage() {
        receiverPreferences.drawReceiver()->receivePackage(sendingBuffer.[0]);
        sendingBuffer.erase(sendingBuffer.begin());
    }
    //Package*
    std::vector<Package> viewSendingBuffer(){
        return sendingBuffer;
    }
};
#endif //NET_SIMULATION_PACKAGESENDER_H
