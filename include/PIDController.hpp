/* Proportional-Integral-Derivative controller
 * https://en.wikipedia.org/wiki/PID_controller
 */

#include <iostream>

class PIDController {
    private:
    // All values initialized as double for greater accuracy
        // Gains
        double Kp = 1;
        double Ki = 1;
        double Kd = 1;

        // Values of interest:
        double e;       // Error value
        double pe;  // previous error needed for derivative
        double integral;  // Integral term starting at zero
        double dt;      // time difference needed for calculus

        // Limits for regulating the values:
        double max_lim, min_lim;

    public:
        PIDController(double p, double i, double d, 
                        double _dt, double _max, double _min):
        Kp(p),
        Ki(i),
        Kd(d),
        dt(_dt),
        integral(0),
        e(0),
        pe(0),
        max_lim(_max),
        min_lim(_min) {}

        double calculate(double sp, double pv) {
            e = sp - pv;

            // Integral part:
            integral += e * dt;  // Possible error

            // Derivative part:
            // double derivative = ;

            // Total PID output:
            double correction = Kp * e + Ki * integral + Kd * ((e - pe) / dt);

            if (correction > max_lim)
                correction = max_lim;
            else if (correction < min_lim)
                correction = min_lim;
            
            pe = e;
            return correction;  // This gets added to the process variable           
        }
};