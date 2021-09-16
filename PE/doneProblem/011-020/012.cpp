#include <bits/stdc++.h>
using namespace std;

int count_div(int n)
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
        ans *= x.at(i) + 1;
    }
    return ans;
}
int main()
{
    int divisors;
    long long num;
    int count;
    int div = 1;
    cin >> divisors;
    count = divisors;
    while (div <= divisors)
    {
        if (count % 2 == 0)
        {
            div = count_div(count / 2) * count_div(count + 1);
        }
        else
        {
            div = count_div(count) * count_div((count + 1) / 2);
        }
        count++;
    }
    count--;
    cout << count * (count + 1) / 2 << "\n";
    return (0);
}
