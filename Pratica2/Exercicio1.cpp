#include <iostream>
#include <algorithm>

using namespace std;

int adigits(int a, int b, int c){
    int d=max(a, max(b, c));
    int e=min(a, min(b, c));
    int f=a+b+c-d-e;
    return d*100+f*10+e*1;
}