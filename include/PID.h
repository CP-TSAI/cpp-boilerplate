/**
* @file PID.h
*
* @brief PID class interface
*  Define the PID controller with kp/ki/kd gain
*  Compute the velocity value according to "setpoint" and "current velocity" 
* 
* @author:
* @copyright:
*/

#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_


/**
* @brief PID class interface
* @param _Kp, _Ki, _Kd The gain values of PID controller
* @param constructor, destructor Initialization and memory control
* @param Compute() return the new velocity according to input param
*/
class PID {
private:
	double _Kp;
	double _Ki;
	double _Kd;

public:
	/* constructor*/
	PID(const double &Kp, const double &Ki, const double &Kd);
	
	/* destructor */
	~PID();
	
	
	double Compute(const double &Set_Point, const double &Current_Velocity);

};

#endif