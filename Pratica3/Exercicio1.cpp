#include <iostream>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    int i=0;
    unsigned long decimal=0;
    while (hstr[i] != '\0'){
        char c=hstr[i];
        unsigned long value=0;
        //cout << c << " " << value << endl;
        if(c>='0' && c<='9') value=c-'0';
        else if(c>='A' && c<='F') value=c-'A'+10;
        else value=c-'a'+10;
        decimal =decimal*16+value;
        //cout << c << " " << value << endl;
        i++;
    }
    return decimal;
}

int main(){
    cout << hstr_to_integer("0");
}