#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int num)
{
    if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
int main()
{
    int num = 20;
    int temp = num;
    long ans = 1;
    int prime = 2;
    while (prime <= num)
    {
        if (IsPrime(prime))
        {
            temp = num;
            while (temp > 0)
            {
                temp /= prime;
                ans *= prime;
            }
            ans /= prime;
        }
        prime++;
    }
    cout << ans << '\n';
    return (0);
}
