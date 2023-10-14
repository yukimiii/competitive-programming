#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long power(int base, int power)
{
    long long num = 1;
    while (power > 0)
    {
        num *= base;
        power--;
    }
    return (num);
}

int main()
{
    vector<string> nums(100);
    ll sum;
    ll num;

    sum = 0;
    for (int i = 0; i < 100; i++)
    {
        num = 0;
        cin >> nums.at(i);
        for (int j = 0; j < 12; j++)
        {
            num += (nums.at(i)[j] - '0') * power(10, 12 - j);
        }
        sum += num;
    }
    cout << sum / 100000 << "\n";
    return (0);
}

//ずううっと上位10桁の和だと思っててできなくて吐きそうだった。
