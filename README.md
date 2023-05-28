# PID (Proportional-Integral-Derivative) Controller

This an implementation of a PID Controller in C++. PID Controller is a popular
controller used for regulation and maintenance of the state of an object at a 
desired value, such as for maintaining the acceleration of a vehicle or for
keeping a drone hovering in air:
https://www.youtube.com/watch?v=wkfEZmsQqiA

Also, Matplot++ library is used in this project. Make sure that you have it installed properly
*Refer to https://github.com/alandefreitas/matplotplusplus#embed-with-cpmcmake for CMake configuration details

To see it run:
1. Create build folder and enter it with `mkdir build && cd build`
2. Initialize CMake and build executable file with `cmake .. && cmake --build .`
3. Run the formed executable with `./PIDController`