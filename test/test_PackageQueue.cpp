//
// Created by pawel on 15.01.2018.
//

#include "gtest/gtest.h"
#include "PackageQueue.h"
#include "types.h"

namespace idCounter {
    int counter = 0;
}

TEST(PackageQueue, sizeAndIsEmpty) {
    PackageQueue q(QueueType::LIFO);
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(0, q.size());
    Package p;
    q.push(p);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(1, q.size());
    idCounter::counter = 0;
}

TEST(PackageQueue, popFunctionLIFO) {
    //is there a way to reset a static variable?
    PackageQueue q(QueueType::LIFO);
    for (int i = 0; i < 10; ++i) {
        Package p;
        q.push(p);
        ++idCounter::counter;
    }
    EXPECT_EQ(q.size(), 10);
    EXPECT_EQ(q.pop().getId(), idCounter::counter);
    --idCounter::counter;
    EXPECT_EQ(q.size(), 9);
}

TEST(PackageQueue, popFunctionFIFO) {
    PackageQueue q(QueueType::FIFO);
    for (int i = 0; i < 10; ++i) {
        Package p;
        q.push(p);
        ++idCounter::counter;
    }
    EXPECT_EQ(q.size(), 10);
    EXPECT_EQ(q.pop().getId(), 11);
    //this package is 11, beouse it was declared after 11 other packages
    //this is to be changed
    --idCounter::counter;
    EXPECT_EQ(q.size(), 9);
}