#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll combination(ll n, ll r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combination(n, r - 1) * (n - r + 1) / r;
}
int main()
{
    ll n;
    int compare;
    cin >> n >> compare;
    int count = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i / 2; j++)
        {
            if (combination(i, j) > compare)
            {
                count += i + 1 - 2 * j;
                break;
            }
        }
    }
    cout << count << "\n";
    return (0);
}
