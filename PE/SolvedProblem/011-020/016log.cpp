#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int sum = 0;
    int base, power;
    cin >> base >> power;
    vector<int> num((int)(power * log10(base) + 1));
    num.at(0) = 1;
    int digit = 1;
    for (int i = 0; i < power; i++)
    {
        for (int j = 0; j < digit; j++)
        {
            num.at(j) *= base;
        }
        for (int j = 0; j < digit; j++)
        {
            if (num.at(j) > 9)
            {
                if (j == digit - 1)
                {
                    digit++;
                }
                num.at(j + 1) += num.at(j) / 10;
                num.at(j) = num.at(j) % 10;
            }
        }
    }
    for (int i = 0; i < digit; i++)
    {
        sum += num[i];
    }
    cout << sum << "\n";
    return (0);
}
