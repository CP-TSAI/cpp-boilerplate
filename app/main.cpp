/** @file main.cpp
 * 
 * @brief This script makes use of the class PID to get the required
 *        PID value for a target setpoint and velocity
 * 
 * @author Chin-Po Tsai
 * @copyright 2018 ,Chin-Po Tsai All rights reserved
*/

#include <iostream>
#include <PID.h>

int main() {
  const double Kp = 1.1;
  const double Ki = 0.5;
  const double Kd = 0.05;

  PID Controller = PID(Kp, Ki, Kd);
  Controller.setConstants(Kp, Ki, Kd);

  const double Set_Point = 200;
  const double Current_Velocity = 20;
  const double Control = Controller.Compute(Set_Point, Current_Velocity);
  std::cout << "New Velocity: " << (Control + Current_Velocity) << std::endl;
  std::cout << "Control: " << Control << std::endl;
  return 0;
}
