#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

void calc_medians(const string& input_fname, const string& output_fname) {
  ifstream in(input_fname);
  ofstream out(output_fname);
  for (string line; getline(in, line); ) { 
    if (line[0] == '#') continue;
    istringstream iss(line);
    string id;         
    iss >> id;
    vector<double> v;  
    for (double x; iss >> x; ) v.push_back(x);
    
    sort(v.begin(), v.end());
    int n = v.size(); 
    double m = n % 2 != 0  ?
      v[n / 2] : 0.5 * (v[n / 2 - 1] + v[n / 2]);

    out << id  << ' ' << fixed << setprecision(1) << m << '\n';
  }
}
