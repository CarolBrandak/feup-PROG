#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a;
    cin >> b;
    for (a; a <= b; a++)
    {
        int decimal=a, binary = 0, remainder, product = 1, cnt = 0;
        while (decimal != 0)
        {
            remainder = decimal % 2;
            if (remainder == 1) cnt++;
            binary = binary + (remainder * product);
            decimal = decimal / 2;
            product *= 10;
        }

        int j = 2, h = 2;
        while (j < a && a % j != 0)
        {
            j++;
        }
        while (h < cnt && cnt % h != 0)
        {
            h++;
        }
        if (a == j && cnt == h)
            cout << a << endl;
    }
}