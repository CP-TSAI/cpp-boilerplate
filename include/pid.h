#ifndef PID_H
#define PID_H


class pid{

private:
	double _kp;
	double _ki;
	double _kd;

public:

	/* constructor */
	pid(const double& kp, const double& ki, const double& kd);

	/* destructor */
	~pid();

	double compute(const double& setPoint, const double& currentVelocity);
};



#endif