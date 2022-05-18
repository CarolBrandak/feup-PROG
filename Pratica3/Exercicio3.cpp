#include <iostream>
using namespace std;

//! Auxiliary function to print n elements of an array.
void print_array(const int a[], int n)
{
  cout << '[' << a[0];
  for (int i = 1; i < n; i++)
  {
    cout << ',' << a[i];
  }
  cout << "]\n";
}

void merge_arrays(const int a[], int na, const int b[], int nb, int c[])
{
  int aindex = 0;
  int bindex = 0;
  int cindex = 0;

  while (cindex < na+nb)
  {
    if(aindex == na){
      c[cindex] = b[bindex];
      bindex++;
      cindex++;
    }
    else if(bindex == nb){
      c[cindex] = a[aindex];
      aindex++;
      cindex++;
    }
    else if (a[aindex] > b[bindex])
    {
      c[cindex] = b[bindex];
      bindex++;
      cindex++;
    }
    else if (a[aindex] <= b[bindex])
    {
      c[cindex] = a[aindex];
      aindex++;
      cindex++;
    }
  }
}