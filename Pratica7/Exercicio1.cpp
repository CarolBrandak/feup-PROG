#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count(const string& fname, const string& word){
    ifstream in (fname);
    int n=0;
    string word_uc=word;
    for (char& c:word_uc)
    {
        c=toupper(c);
    }
    for (string s; in>>s;)
    {
        for (char& c:s)
        {
            c=toupper(c);
        }
        if(s==word_uc) n++;
    }
    return n;
}