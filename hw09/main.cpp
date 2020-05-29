#include<iostream>
#include<math.h>
#include"funciones.h"

using namespace std;


//RK4 size for each step
double* RK4(double y, double v, double t, double dt){
    
    //k1
    double yk1 = dt * dy_dt(t, v);
    double vk1 = dt * dv_dt(t, v);
    //k2
    double yk2 = dt * dy_dt(t + dt * 0.5, v + 0.5 * yk1);
    double vk2 = dt * dv_dt(t + dt * 0.5, v + 0.5 * vk1);
    //k3
    double yk3 = dt * dy_dt(t + dt * 0.5, v + 0.5 * yk2);
    double vk3 = dt * dv_dt(t + dt * 0.5, v + 0.5 * vk2);
    //k4
    double yk4 = dt * dy_dt(t + dt * 1.0, v + 1.0 * yk3);
    double vk4 = dt * dv_dt(t + dt * 1.0, v + 1.0 * vk3);
    //step
    
    double* res = new double[2];
    
    res[0] =  1.0 / 6.0 * (yk1 + 2.0 * yk2 + 2.0 * yk3 + yk4);
    res[1] =  1.0 / 6.0 * (vk1 + 2.0 * vk2 + 2.0 * vk3 + vk4);
    
    return res;
}

//main function
int main(){
    
    //Inticial conditions
    double y0 = 8.50, v0 =  20.0, t0 = 0.00; //inicial height [m], incial velocity [m/s], inicial time [s]
        
    //RK4 conditions
    double dt = 0.010; // step's size [s], stept's amount
    int n = 450;
    
    //Arrays
    double* t = new double[n];
    double* y = new double[n];
    double* v = new double[n];
    
    t[0] = t0, y[0] = y0, v[0] = v0;
        
        
    for (int i = 0; i < n - 1; ++i) {
        double* step = RK4(y[i], v[i], t[i], dt);
        t[i + 1] = t[i] + dt;
        y[i + 1] = y[i] + step[0];
        v[i + 1] = v[i] + step[1];
            
        cout << t[i] << " " << y[i] << " " << v[i] << endl;
    }
    
    return 0;
}