
#include<iostream>
#include <stdexcept>
#include "PID.h"

PID::PID(const double &Kp, const double &Ki, const double &Kd) {
  if (Kp < 0 || Ki < 0 || Kd < 0)
    throw std::domain_error("Kp,Ki,Kd Cannot be Negative");
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

PID::~PID() {}

double PID::Compute(const double &Set_Point, const double &Current_Velocity) {
  const double dt = 0.2;
  const double Error = Set_Point - Current_Velocity;
  const double Integral = Error * dt;
  const double Derivative = Error / dt;
  const double New_Velocity = _Kp * Error + _Ki * Integral + _Kd * Derivative;
  return New_Velocity;
}


