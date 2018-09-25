/**
<<<<<<< HEAD
 * @file test.cpp
 * @brief Unit Tests for PID Controller Implementation
 * @author Chin-Po Tsai
 * @copyright 2018, Chin-Po Tsai
 */
=======
* @file test.cpp
*
* @brief Tests the class PID
*  Computes the PID output and compares it
*  Checks the input function 
* 
* @author: Chin-Po Tsai
* @copyright: [2017] <Chin-Po Tsai>  [legal/copyright]

*/

>>>>>>> 51e15b6900c7debae51a0b4fbcff55d50e9d1217

#include <gtest/gtest.h>
#include "PID.h"

TEST(Compute, should_pass) {
    PID controller = PID(1, 0, 0);
<<<<<<< HEAD
    EXPECT_EQ(3, controller.Compute(4,1));
=======
    EXPECT_EQ(3, controller.Compute(4, 1));
>>>>>>> 51e15b6900c7debae51a0b4fbcff55d50e9d1217
}

TEST(setConstants, should_pass) {
    PID controller;
    controller.setConstants(1.1, 0.5, 0.05);
    EXPECT_EQ(1.1, controller.getKp());
    EXPECT_EQ(0.5, controller.getKi());
    EXPECT_EQ(0.05, controller.getKd());
}
