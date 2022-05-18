#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;
 
struct wcresult {
  unsigned int lines;
  unsigned int words; 
  unsigned int bytes; 
};

wcresult wc(const string& filename){
    ifstream in(filename);
    wcresult r{0,0,0};
    for(string line; getline(in, line);){
        r.lines++;
        r.bytes+=line.length()+1;
        istringstream iss(line);
        for (string s; iss>> s;)
        {
            r.words++;
        }
    }
    return r;
}
