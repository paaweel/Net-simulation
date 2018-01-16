//
// Created by pawel on 16.01.2018.
//

#ifndef NET_SIMULATION_SIMULATE_H
#define NET_SIMULATION_SIMULATE_H

#include <functional>
#include "Types.h"
#include "Factory.h"

void simulate(Factory factory, TimeOffset timeOffset, std::function(Factory&, TimeOffset) );

#endif //NET_SIMULATION_SIMULATE_H
