#include <iostream>
using namespace std;

//! Print array.
void print(int a[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "]";
    cout << endl;
}

void remove_duplicates(int a[], int &size)
{

    int index = 1;
    for (int i = 1; i < size; i++)
    {
        if (a[index] != a[i - 1])
        {
            index++;
            a[index] = a[i];
        }
    }
    size = index;
}