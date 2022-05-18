#include <iostream>
using namespace std;

//! Complex number
struct complex
{
  int real; // Real part
  int img;  // Imaginary part
};

//! Print array of complex numbers.
void print(const complex z[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
  {
    if (z[i].real == 0 && z[i].img == 0)
      cout << 0;
    else
    {
      if (z[i].real != 0)
        cout << z[i].real;
      if (z[i].img > 0)
        cout << '+' << z[i].img << 'i';
      else if (z[i].img < 0)
        cout << z[i].img << 'i';
    }
    cout << ' ';
  }
  cout << "]\n";
}

complex sum(complex c1, complex c2)
{
  complex c = {0, 0};
  c.real = c1.real + c2.real;
  c.img = c1.img + c2.img;
  return c;
}

complex mull(complex c1, complex c2)
{
  complex c = {0, 0};
  c.real = c1.real * c2.real - c1.img * c2.img;
  c.img = c1.real * c2.img + c2.real * c1.img;
  return c;
}

void mandel(complex c, int n, complex z[])
{
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
      z[i] = {0, 0};
    else
    {
      z[i] = sum(mull(z[i - 1], z[i - 1]), c);
    }
  }
}

int main()
{
  complex c = {1, 1};
  const int n = 3;
  complex z[n];
  mandel(c, n, z);
  print(z, n);
  return 0;
}