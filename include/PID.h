#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

class PID {
 private:
  double _Kp, _Ki, _Kd;
 public:
  PID(const double &Kp, const double &Ki, const double &Kd);
  ~PID();
  double Compute(const double &Set_Point, const double &Current_Velocity);
  
};

#endif