/** @file PID.cpp
 * 
 * @brief This script implements the function defined in PID.h
 * 
 * @author Chin-Po Tsai
 * @copyright 2018 ,Chin-Po Tsai All rights reserved
*/

#include<iostream>
#include <stdexcept>
#include "PID.h"

/**
 * @brief Constructor
 * @param Kp proportional gain
 * @param Ki integral gain
 * @param Kd differential gain
 */
PID::PID(const double &Kp, const double &Ki, const double &Kd) {
  setConstants(Kp, Ki, Kd);
}

/**
 * @brief Constructor. Initialize the PID gain.
 */
PID::PID() {
  _Kp = 0;
  _Ki = 0;
  _Kd = 0;
}

/**
 * @brief Destructor
 */
PID::~PID() {}

/**
 * @brief get the value of Kp
 */
double PID::getKp(void) {
  return _Kp;
}

/**
 * @brief get the value of Ki
 */
double PID::getKi(void) {
  return _Ki;
}

/**
 * @brief get the value of Kd
 */
double PID::getKd(void) {
  return _Kd;
}

/**
 * @brief compute the control value
 * @param setPoint Reference Value
 * @param currentVelocity Current Velocity Value
 * @return velocity
 */
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

/**
 * @brief Initialize the PID value
 * @param Kp proportional gain
 * @param Ki integral gain
 * @param Kd differential gain
 * @return void
 */
void PID::setConstants(const double &Kp, const double &Ki, const double &Kd) {
    _Kp = Kp;
    _Kd = Kd;
    _Ki = Ki;
}


