#include <iostream>
#include <map>

using namespace std;

unsigned roman_to_arab(const string &roman)
{
    static map<char, unsigned> map_roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    unsigned soma = 0;
    for (size_t i = 0, n = roman.length(); i < n; i++)
    {
        unsigned dec=map_roman[roman[i]];
        if (i < n - 1 && dec < map_roman[roman[i + 1]]){
            soma -= dec;
        }    
        else{
            soma += dec;
        }
    }
    return soma;
}

