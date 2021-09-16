#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ans_digit == 1の時の処理は面倒だから省略
int main()
{
    int index = 4;
    int ans_digit;
    cin >> ans_digit;
    int digit = 1;
    int carry = 0;

    vector<int> fibo0(ans_digit);
    vector<int> fibo1(ans_digit);
    vector<int> fibo2(ans_digit);

    fibo0[0] = 2;
    fibo1[0] = 1;
    fibo2[0] = 1;
    while (digit < ans_digit)
    {
        if (index % 3 == 0)
        {
            for (int i = 0; i < digit; i++)
            {
                fibo0[i] = fibo1[i] + fibo2[i] + carry;
                carry = 0;
                if (fibo0[i] > 9)
                {
                    fibo0[i] -= 10;
                    carry = 1;
                    if (i == digit - 1)
                    {
                        digit++;
                    }
                }
            }
        }
        if (index % 3 == 1)
        {
            for (int i = 0; i < digit; i++)
            {
                fibo1[i] = fibo2[i] + fibo0[i] + carry;
                carry = 0;
                if (fibo1[i] > 9)
                {
                    fibo1[i] -= 10;
                    carry = 1;
                    if (i == digit - 1)
                    {
                        digit++;
                    }
                }
            }
        }
        if (index % 3 == 2)
        {
            for (int i = 0; i < digit; i++)
            {
                fibo2[i] = fibo0[i] + fibo1[i] + carry;
                carry = 0;
                if (fibo2[i] > 9)
                {
                    fibo2[i] -= 10;
                    carry = 1;
                    if (i == digit - 1)
                    {
                        digit++;
                    }
                }
            }
        }
        index++;
    }
    cout << index - 1 << "\n";
    return (0);
}
