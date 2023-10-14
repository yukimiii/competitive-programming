#include <bits/stdc++.h>
using namespace std;

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
int amicable(int n)
{
    vector<int> x(n + 1);
    int num = n;
    int ans = 1;

    for (int i = 2; i <= n; i++)
    {
        while (num % i == 0)
        {
            x.at(i)++;
            num /= i;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        ans *= (power(i, 1 + x.at(i)) - 1) / (i - 1);
    }
    return ans - n;
}

int main()
{
    int ans = 0;
    int N;
    int ami;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        ami = amicable(i);
        if (ami > i && ami < N && amicable(ami) == i)
        {
            ans += ami + i;
        }
    }
    cout << ans << "\n";
    return (0);
}
