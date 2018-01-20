//
// Created by pawel on 12.01.2018.
//

#include "gtest/gtest.h"
#include "../include/ReceiverPreferences.h"
#include "../include/ramp.h"
#include "../include/StoreHouse.h"

TEST(ReceiverPreferences, sumEqualsOneWhenAddingNew) {
    auto s0 = std::make_shared<StoreHouse> (0),
            s1 = std::make_shared<StoreHouse> (1),
            s2 = std::make_shared<StoreHouse> (2);

    ReceiverPreferences rp;
    rp.addReceiver(s0.get());
    rp.addReceiver(s1.get());
    double sum = 0.0;
    auto prob = rp.getPreferences();
    for (auto m : prob) {
        sum += m.second;
        std::cout << m.second << " " << sum << std::endl;
    }
    EXPECT_DOUBLE_EQ(sum, 1.0);
    rp.addReceiver(s2.get());
    sum = 0.0;
    prob = rp.getPreferences();
    for (auto m : prob) {
        sum += m.second;
        std::cout << m.second << " " << sum << std::endl;
    }
    EXPECT_DOUBLE_EQ(sum, 1.0);
}

TEST(ReceiverPreferences, SumEqualsOneWhenAddingWithP) {
    auto s0 = std::make_shared<StoreHouse> (0),
            s1 = std::make_shared<StoreHouse> (1),
            s2 = std::make_shared<StoreHouse> (2);

    ReceiverPreferences rp;
    rp.addReceiver(s0.get());
    rp.addReceiver(s1.get(),0.3);
    double sum = 0.0;
    auto prob = rp.getPreferences();
    for (auto m : prob) {
        sum += m.second;
        std::cout << m.second << " " << sum << std::endl;
    }
    EXPECT_DOUBLE_EQ(sum, 1.0);
    rp.addReceiver(s2.get(),0.5);
    sum = 0.0;
    prob = rp.getPreferences();
    for (auto m : prob) {
        sum += m.second;
        std::cout << m.second << " " << sum << std::endl;
    }
    EXPECT_DOUBLE_EQ(sum, 1.0);

}

TEST(ReceiverPreferences, addingWithProbability) {
    auto s0 = std::make_shared<StoreHouse> (0),
            s1 = std::make_shared<StoreHouse> (1),
            s2 = std::make_shared<StoreHouse> (2);

    ReceiverPreferences rp;

    rp.addReceiver(s0.get(), 0.3);

    auto prob = rp.getPreferences();
    EXPECT_DOUBLE_EQ(1.0, prob[s0.get()]);

    rp.addReceiver(s1.get(), 0.3);
    prob = rp.getPreferences();
    EXPECT_DOUBLE_EQ(0.7, prob[s0.get()]);
    EXPECT_DOUBLE_EQ(0.3, prob[s1.get()]);
}

TEST (ReceiverPreferences, removingReceiver) {
    auto s0 = std::make_shared<StoreHouse> (0),
            s1 = std::make_shared<StoreHouse> (1),
            s2 = std::make_shared<StoreHouse> (2);

    ReceiverPreferences rp;
    std::map<IPackageReceiver*, double>  newPref = {{s0.get(), 0.2}, {s1.get(), 0.4}, {s2.get(),0.4}};
    rp.setPreferences(newPref);

    rp.removeReceiver(s0.get());

    auto prob = rp.getPreferences();
    EXPECT_DOUBLE_EQ(0.5, prob[s1.get()]);
    EXPECT_DOUBLE_EQ(0.5, prob[s2.get()]);

}
