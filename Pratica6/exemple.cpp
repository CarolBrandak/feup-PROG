#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    string s="Butterfly";
    for(char& c:s){
        if(c>='a' && c<='l')
            c=toupper(c);
    }
    for(char c: s) cout << c;

    cout << '\n';
}