/**
 * @file test.cpp
 * @brief Unit Tests for PID Controller Implementation
 * @author Chin-Po Tsai
 * @copyright 2018, Chin-Po Tsai
 *
*/

#include <gtest/gtest.h>
#include "PID.h"

/**
 * @brief test for checking whether the "Compute()" function is correct
 */
TEST(Compute, should_pass) {
    PID controller = PID(1, 0, 0);
    EXPECT_EQ(3, controller.Compute(4, 1));
}

/**
 * @brief test for checking whether the access function to the private variable is correct
 */
TEST(setConstants, should_pass) {
    PID controller;
    controller.setConstants(1.1, 0.5, 0.05);
    EXPECT_EQ(1.1, controller.getKp());
    EXPECT_EQ(0.5, controller.getKi());
    EXPECT_EQ(0.05, controller.getKd());
}
