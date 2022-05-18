#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double average(const string& fname){
    ifstream in(fname);
    double sum=0;
    int n=0;
    while(!in.eof()){
        double x;
        if(in>>x){
            sum+=x;
            n++;
        }else{
            in.clear();
            in.ignore(1);
        }
    }
    return sum/n;
}