#include <iostream>

using namespace std;

bool anagrams(const char a[], const char b[], int &n)
{
    int count[26] = {0};

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ')
        {
            if (a[i] >= 'a' && a[i] <= 'z')
                count[a[i] - 'a']++;
            else
                count[a[i] - 'A']++;
        }
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] != ' ')
        {
            if (b[i] >= 'a' && b[i] <= 'z')
                count[b[i] - 'a']--;
            else
                count[b[i] - 'A']--;
        }
    }

    n = 0;
    for (int i = 0; i < 26; i++)
    {
        n += abs(count[i]);
    }
    return (n == 0);
}