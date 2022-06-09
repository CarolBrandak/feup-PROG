#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cfloat>

using namespace std;

//! Show file name and its contents.
void show_file(const string &file)
{
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line);)
    cout << line << '\n';
}

bool average(const string &input_fname, const string &output_fname)
{
  int coy=0;
  ifstream in(input_fname);
  if (in.fail())
    return false;

  ofstream out(output_fname);
  if (in.fail())
    return false;

  for (string line; getline(in, line);coy++)
  {
    istringstream iss(line);
    double x;
    double res = 0;
    int count = 0;
    while (iss >> x)
    {
      res += x;
      count++;
    }
    out << fixed << setprecision(3) << res / count << endl;
  }
  out << "lines=" << coy;
  return true;
}