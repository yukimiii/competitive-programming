#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<int> num(1, 1);
    int sum = 0;
    int N;
    cin >> N;
    int digit = 1;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < digit; j++)
        {
            num.at(j) *= i;
        }
        for (int j = 0; j < digit; j++)
        {
            if (num.at(j) > 9)
            {
                if (j == digit - 1)
                {
                    digit++;
                    num.resize(digit);
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
}
