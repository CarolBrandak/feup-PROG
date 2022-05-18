#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//! Show file contents with line number information and 
//! the '|' character indicating the begining and end of lines.
void print(const std::string& file) {
  ifstream in(file);
  size_t line_nr = 1;
  for (string line; getline(in, line);) {
     cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}

void normalise(const string& input_fname, const string& output_fname){
    ofstream out(output_fname);
    ifstream in(input_fname);
    for(string line; getline(in, line);){
        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ')+1);
        for (char& c:line)
        {
            c=toupper(c);
        }
        if(line.length()>0){
            out << line << '\n';
        }
    }

}