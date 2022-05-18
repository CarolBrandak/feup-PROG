#include <iostream>

using namespace std;

int main(){

    char ch;
    cin >> ch;
    if(ch>='A' && ch <='Z')
        cout << "LETTER";
    else if(ch>='a' && ch <='z')
        cout << "LETTER";
    else if(ch>='0' && ch <='9')
        cout << "DIGIT";   
    else {
        cout << "OTHER";
    }
    return 0;
}