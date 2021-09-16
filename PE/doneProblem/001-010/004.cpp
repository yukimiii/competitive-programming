#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    long y;
    int tmp;
    tmp = x;

    if (x < 0)
    {
        return (false);
    }
    y = 0;
    while (x > 0)
    {
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    if (y == tmp)
    {
        return (true);
    }
    return (false);
}

int main()
{
    int num;
    num = 997799;
    while (num > 10000)
    {
        for (int i = 999; i > 100; i--)
        {
            if (num % i == 0 && (num / i) >= 100 && (num / i) <= 999)
            {
                if (isPalindrome(num) == 1)
                {
                    cout << num << "/n";
                    return (0);
                }
            }
        }
        num--;
    }
    return (0);
}
