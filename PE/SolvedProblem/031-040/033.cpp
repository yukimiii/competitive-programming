#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a, b, c;
    int proa, prob;
    proa = 1;
    prob = 1;
    for (a = 1; a < 10; a++)
    {
        for (b = 1; b < 10; b++)
        {
            for (c = 1; c < 10; c++)
            {
                if ((10 * a + c) * b == (10 * c + b) * a)
                {
                    if (a == b)
                    {
                        continue;
                    }
                    proa *= a;
                    prob *= b;
                }
            }
        }
    }
    cout << prob / gcd(proa, prob) << "\n";
    return (0);
}
