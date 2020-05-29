#include<iostream>
#include<math.h>

using namespace std;

// Real constant 
const float g = 9.81; 

// Height's derivate
double dy_dt(double t, double v){
    return v;
}

// Velocity's derivate
double dv_dt(double t, double v){
    return - g;
}
