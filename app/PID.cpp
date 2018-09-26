#include<iostream>
#include <stdexcept>
#include "PID.h"

PID::PID(const double &Kp, const double &Ki, const double &Kd) {
  setConstants(Kp, Ki, Kd);
}

PID::PID(){
  _Kp = 0;
  _Ki = 0;
  _Kd = 0;
}

PID::~PID() {}

double PID::getKp(void){
  return _Kp;
}

double PID::getKi(void){
  return _Ki;
}

double PID::getKd(void){
  return _Kd;
}

double PID::Compute(const double &setPoint, const double &currentVelocity) {
    const double Delta = 0.01;  /*!< delta_t for differentiation*/
    double error;                   /*!< Delaring the Error term*/
    double prevError = 0;
    error = setPoint - currentVelocity;   /*!< Error computation*/
    double integral = 0;
    integral += error;           /*!< Updation of integral error*/
     /*!< PID output computation*/
    double v = _Kp*error + _Ki*integral + _Kd*(error - prevError)/Delta;
    prevError = error;           /*!< Previous error computation*/
    return v;
}

void PID::setConstants(const double &Kp, const double &Ki, const double &Kd){
	_Kp = Kp;
	_Kd = Kd;
	_Ki = Ki;
}


