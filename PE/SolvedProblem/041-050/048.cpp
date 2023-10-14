#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tendigitmod = 10000000000;

long long power_mod(int base, int power)
{
    long long num = 1;
    while (power > 0)
    {
        num *= base;
        num = num % tendigitmod;
        power--;
    }
    return (num);
}

int main()
{
    int N;
    cin >> N;

    ll sum;
    ll powmod;
    sum = 0;
    for (int i = 1; i < N + 1; i++)
    {
        sum += power_mod(i, i);
        sum = sum % tendigitmod;
    }
    cout << sum << "\n";
    return (0);
}
