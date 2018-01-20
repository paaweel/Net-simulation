//
// Created by pawel on 12.01.2018.
//

#include <iostream>
#include "include/ReceiverPreferences.h"
#include <simulate.h>

int main() {
    Factory factory;

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

    //put path to your input file
    //as second parameter
    load(factory, R"(C:\2programowanie\cplpl\Net-simulation\input.txt)");
    simulate(factory, 2);
    return 0;
}