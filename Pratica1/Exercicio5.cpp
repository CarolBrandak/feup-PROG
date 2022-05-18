#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(void)
{
    int k, d;
    double result=0;
    cin >> k;
    cin >> d;
    for (int i = 0; i <= k; i++)
    {
        result+= 4*(pow(-1,i)/(2*i+1));
    }
    cout << setprecision(d)<<fixed<<result;
}