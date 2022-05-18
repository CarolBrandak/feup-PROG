#include <string>
#include <vector>
#include <iostream>
using namespace std;

//! Print vector of strings.
void print(const vector<string> &v)
{
    cout << "[ ";
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << '\"' << v[i] << "\" ";
    }
    cout << "]\n";
}

void split(const string &s, vector<string> &v)
{
    size_t pos = 0;
    while (pos < s.length())
    {
        if (s[pos] == ' ')
        {
            pos++;
        }
        else
        {
            size_t end = s.find(' ', pos);
            if (end == string::npos)
            {
                end = s.length();
            }
            v.push_back(s.substr(pos, end - pos));
            pos=end++;
        }
    }
}

int main(){
    string s = "";
    vector<string> v;
    split(s, v);
    print(v);
    return 0;
}