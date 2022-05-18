#include <iostream>
#include <string>
using namespace std;

bool pangram(const string &s, string &m)
{
    int count[26] = {0};
    // existing chars
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A']++;
        }
    }

    // missing chars
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == 0)
        {
            m.push_back(i + 'a');
        }
    }

    return (m.length() == 0);
}

int main(){
    string s = "";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " << boolalpha << r << " \"" << m << "\"\n";
    return 0;
}