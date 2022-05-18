#include <iostream>

using namespace std;

struct fraction {
   int num; // Numerator
   int den; // Denominator
};

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

fraction sum(const fraction fa[], int n){
    fraction result{0,1};
    int i=0;
    while (i<n){
        result.num = result.num * fa[i].den + result.den * fa[i].num;
        result.den *= fa[i].den;
        i++;
   
        int g=gcd(result.num,result.den);
        result.num /= g;
        result.den /= g;
    }
    if(result.den<0){
        result.den-=result.den;
        result.num-=result.num;
    }

    return result;
}
