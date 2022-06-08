#include <map>
#include <list>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

string cat_keys(list<map<string, unsigned>> lst)
{
    unsigned min = UINT_MAX;
    string result;
    for (auto m : lst)
    {
        for (auto p : m)
        {
            if (p.second < min)
            {
                min = p.second;
                result = "";
                for (auto p : m)
                {
                    result.append(p.first);
                }
            }
        }
    }
    return result;
}