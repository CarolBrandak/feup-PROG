#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

//! print map in one line
void show_map(const map<string, size_t> &count)
{
    cout << "[ ";
    for (const auto &e : count)
    {
        cout << e.first << ":" << e.second << ' ';
    }
    cout << "]\n";
}

void count_words(const string &str, map<string, size_t> &count)
{
    istringstream iss(str);
    string word;
    while (iss >> word)
    {
        for (char &c : word)
        {
            c = tolower(c);
        }
        count[word]++;
    }
}

int main(){
    string s = "If you want to buy  buy  if you don't want to buy  bye bye";
    map<string, size_t> count; 
    count_words(s, count);
    show_map(count);
    return 0;
}