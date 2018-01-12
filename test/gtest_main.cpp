//
// Created by pawel on 12.01.2018.
//

#include <cstdio>
#include "gtest/gtest.h"

GTEST_API_ main(int argc, char **argv) {
    printf("Running tests!\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
