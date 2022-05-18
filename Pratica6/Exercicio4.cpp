#include <string>
#include <vector>
#include <iostream>
using namespace std;

string longest_prefix(const vector<string> &v)
{
    string str = "";
    int i = 0;
    for (char e : v[0])
    {
        for (string s : v)
        {
            if (s[i] != e)
            {
                return str;
            }
        }
        str.push_back(v[0][i]);
        i++;
    }
    return str;
}