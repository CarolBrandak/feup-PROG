#include <iostream>

using namespace std;

bool is_mersenne_number(unsigned long n){
    if (n==0){
        return false;
    }
    for (int i = 0; 0 < n; i++)
    {
        if (n%2==0){
            return false;
        }
        n/=2;
    }
    return true;
}