#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num = 600851475143;
    int lastfactor = 1;
    int factor = 3;
    while (factor <= num / factor)
    {
        while (num % factor == 0)
        {
            num /= factor;
            lastfactor = factor;
        }
        factor += 2;
    }
    cout << num << '\n';
    return (0);
}
