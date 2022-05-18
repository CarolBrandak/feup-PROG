#include <iostream>
#include <cmath>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    double delta=pow(b,2)*(4*a*c);
    if(delta>0){
        x1=(((-1)*b)-sqrt(delta))/(2.0*a);
        x2=(((-1)*b)+sqrt(delta))/(2.0*a);
        return 2;
    }

    if(delta==0){
        x1=((-1)*b)/(2.0*a);
        x2=NAN;
        return 1;
    }
    
    else{
        x1=NAN;
        x2=NAN;
        return 0;
    }

}