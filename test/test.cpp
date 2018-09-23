#include <gtest/gtest.h>
#include "PID.h"

TEST(Compute, should_pass) {
	PID controller = PID(1, 0, 0);
	EXPECT_EQ(3, controller.Compute(4,1));
}

TEST(setConstants, should_pass){
	PID controller;
	controller.setConstants(1.1, 0.5, 0.05);
	EXPECT_EQ(1.1, controller.getKp());
	EXPECT_EQ(0.5, controller.getKi());
	EXPECT_EQ(0.05, controller.getKd());
}
