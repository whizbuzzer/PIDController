/* PID Controller Implementation */

#include <iostream>
#include <vector>

#include <matplot/matplot.h>
#include "PIDController.hpp"


int main() {
    // Time range for plotting:
    double dt = 0.1;
    std::vector<double> t = {0};
    for(double i = 0.1; i < 5; i += dt) {
        t.push_back(i);
    }

    // Parameters to be fed into the PID Controller:
    std::vector<double> Kp = {0.1, 0.1, 0.1};
    std::vector<double> Ki = {0.0, 0.1, 0.1};
    std::vector<double> Kd = {0.0, 0.0, 0.09};

    // Value limits:
    double MAX = 100, MIN = -100;

    // Storing values for plotting:
    std::vector<double> values0 = {20}, values1 = {20}, values2 = {20};


    PIDController pid0(Kp[0], Ki[0], Kd[0], dt, MAX, MIN);
    PIDController pid1(Kp[1], Ki[1], Kd[1], dt, MAX, MIN);
    PIDController pid2(Kp[2], Ki[2], Kd[2], dt, MAX, MIN);

    // Running the PID controllers to bring values to the ideal value:
    for (int i = 1; i < 50; i++) {
        double curr_val0 = values0[i - 1];
        double pv0 = pid0.calculate(0, curr_val0);
        // std::cout << pv0 << std::endl;
        curr_val0 += pv0;
        values0.push_back(curr_val0);

        double curr_val1 = values1[i - 1];
        double pv1 = pid1.calculate(0, curr_val1);
        curr_val1 += pv1;
        values1.push_back(curr_val1);

        double curr_val2 = values2[i - 1];
        double pv2 = pid2.calculate(0, curr_val2);
        curr_val2 += pv2;
        values2.push_back(curr_val2);
    }

    for (int i = 0; i < values0.size(); i++) {
        std::cout << values0.size() << std::endl;
        std:: cout << "State0: " << values0[i] << ", State1: " << values1[i] << ", State2: " << values2[i] << std::endl;
    }

    std::vector<double> zeros(values0.size(), 0.0);

    std::vector<std::string> newcolors = {"#D41243", "#5F2AF0", "#1B8712", "#6D0870"};
    matplot::colororder(newcolors);

    matplot::plot(t, values0)->line_width(2);
    matplot::hold(matplot::on);
    matplot::plot(t, values1)->line_width(2);
    matplot::plot(t, values2)->line_width(2);
    matplot::plot(t, zeros)->line_width(2);
    matplot::hold(matplot::off);
    matplot::ylim({MIN, MAX});

    auto l = matplot::legend({"PID0", "PID1", "PID2", "Steady value"});
    l->location(matplot::legend::general_alignment::topright);
    l->num_rows(2);

    matplot::title("Using PID Controller to rectify a value");
    matplot::xlabel("Time (s)");
    matplot::ylabel("State (unit)");
    matplot::grid(matplot::on);
    matplot::show();

    return 0;
}