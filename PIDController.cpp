/**********************************************
* Proportional-Integral-Derivative controller *
**********************************************/

#include <iostream>

class PIDController {
    private:
        float Kp = 1;
        float Ki = 1;
        float Kd = 1;
    public:
        PIDController(float p=1, float i=1, float d=1) {

            Kp = p;
            Ki = i;
            Kd = d;

        }

        PIDController() {}

        float run() {
            
        }
};

int main() {
    std::cout << "Hello, world!" << std::endl;
}