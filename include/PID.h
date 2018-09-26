/**
* @file PID.h
*
* @brief PID class interface
*  Define the PID controller with kp/ki/kd gain
*  Compute the velocity value according to "setpoint" and "current velocity" 
* 
* @author: Chin-Po Tsai
* @copyright: 2018 ,Chin-Po Tsai All rights reserved
*/

#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

/**
* @brief PID class to implement a PID controller
* @param none
*/
class PID {
 private:
    double _Kp;
    double _Ki;
    double _Kd;

 public:
    /**
    * @brief default constructor to initialize default values for Kp, Kd, Ki
    * @param none
    * @return none
    */
    PID();

    /**
    * @brief constructor to initialize Kp, Kd, Ki with the given values
    * @param Kp, Kd, Ki
    * @return none
    */	
    PID(const double& Kp, const double& Ki, const double& Kd);

    /* destructor */
    ~PID();

    /**
    * @brief returns the value of Kp
    * @param none
    * @return returns a double value of Kp
    */	
    double getKp(void);

    /**
    * @brief returns the value of Ki
    * @param none
    * @return returns a double value of Ki
    */
    double getKi(void);

    /**
    * @brief returns the value of Kd
    * @param none
    * @return returns a double value of Kd
    */
    double getKd(void);

    /**
    * @brief sets the value for the constants Kp, Kd, Ki
    * @param Kp, Ki, Kd
    * @return none
    */
    void setConstants(const double& Kp, const double& Ki, const double& Kd);

    /**
    * @brief compute the required velocity for the given setpoint and actual velocity
    * @param setpoint, currentVelocity
    * @return required velocity
    */
    double Compute(const double& setPoint, const double& currentVelocity);
};

#endif  // INCLUDE_PID_H_
