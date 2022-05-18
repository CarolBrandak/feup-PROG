#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int j = 2;
        while (j < i && i % j != 0)
        {
            j++;
        }
        if (i == j)
            cout << i << endl;
    }
}