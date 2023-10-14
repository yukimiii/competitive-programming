#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int num)
{
    if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    long long prime;
    prime = 1;
    cin >> n;
    n--;
    while (n > 0)
    {
        prime += 2;
        if (IsPrime(prime))
        {
            n--;
        }
    }
    cout << prime << '\n';
    return (0);
}
