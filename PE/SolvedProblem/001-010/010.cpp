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
    int N;
    long long sum;
    int prime;

    prime = 3;
    sum = 2;
    cin >> N;
    while (prime < N)
    {
        if (IsPrime(prime))
        {
            sum += prime;
        }
        prime += 2;
    }
    cout << sum << "\n";
    return (0);
}
