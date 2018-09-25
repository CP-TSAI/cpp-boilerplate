/**
* @file PID.h
*
* @brief PID class interface
*  Define the PID controller with kp/ki/kd gain
*  Compute the velocity value according to "setpoint" and "current velocity" 
* 
* @author: Chin-Po Tsai
* @copyright: [2017] <Chin-Po Tsai>  [legal/copyright]

*/

#ifndef CPP_BOILERPLATE__INCLUDE_PID_H_
#define CPP_BOILERPLATE__INCLUDE_PID_H_


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
    PID(const double Kp, const double Ki, const double Kd) {
      setConstants(Kp, Ki, Kd);
}

/**
* @brief constructor to initialize Kp, Kd, Ki with the given values
* @param Kp, Kd, Ki
* @return none
*/	
    PID() {}
    /* destructor */
    ~PID() {}

/**
* @brief returns the value of Kp
* @param none
* @return returns a double value of Kp
*/	
    double getKp(void) {
        return _Kp;
    }

/**
* @brief returns the value of Ki
* @param none
* @return returns a double value of Ki
*/
    double getKi(void) {
        return _Ki;
    }

/**
* @brief returns the value of Kd
* @param none
* @return returns a double value of Kd
*/
    double getKd(void) {
        return _Kd;
    }

/**
* @brief sets the value for the constants Kp, Kd, Ki
* @param Kp, Ki, Kd
* @return none
*/
    void setConstants(const double Kp, const double Ki, const double Kd) {
        _Kp = Kp;
        _Kd = Kd;
        _Ki = Ki;
    }
/**
* @brief compute the required velocity for the given setpoint and actual velocity
* @param setpoint, currentVelocity
* @return required velocity
*/
    double Compute(const double setPoint, const double currentVelocity) {
        const double Delta = 0.01;
        double error;
        double prevError = 0;
        error = setPoint - currentVelocity;
        double integral = 0;
        integral += error;

        double v = _Kp*error + _Ki*integral + _Kd*(error - prevError)/Delta;
        prevError = error;
        return v;
    }
};

#endif  // CPP_BOILERPLATE__INCLUDE_PID_H_
