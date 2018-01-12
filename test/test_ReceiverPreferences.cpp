//
// Created by pawel on 12.01.2018.
//

#include "gtest/gtest.h"
#include "../include/ReceiverPreferences.h"
#include "../include/ramp.h"
#include "../include/StoreHouse.h"


TEST(ReceiverPreferences, sumEqualsOne) {

    auto s0 = std::make_shared<StoreHouse> (0),
            s1 = std::make_shared<StoreHouse> (1),
            s2 = std::make_shared<StoreHouse> (2);

    auto r0 = std::make_shared<Ramp> (3,1),
            r1 = std::make_shared<Ramp> (4,1);
    ReceiverPreferences rp;
    rp.addReceiver(s0.get());
    rp.addReceiver(s1.get());
    double sum = 0;
    auto prob = rp.getPreferences();
    for (auto m : prob) {
        sum += m.second;
    }
    ASSERT_EQ(sum, 1.0);
    rp.addReceiver(s2.get());
    sum = 0;
    prob = rp.getPreferences();
    for (auto m : prob) {
        sum += m.second;
    }
    ASSERT_EQ(sum, 1.0);
}

