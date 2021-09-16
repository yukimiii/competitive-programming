#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int maxnum;
    cin >> maxnum;

    int longest = 0;
    int count;
    ll tmp;
    int ans;

    for (int i = maxnum - 1; i > maxnum / 2; i--)
    {
        count = 1;
        tmp = i;
        while (tmp > 1)
        {
            if (tmp % 2 == 0)
            {
                tmp /= 2;
            }
            else
            {
                tmp = 3 * tmp + 1;
            }
            count++;
        }
        if (longest < count)
        {
            longest = count;
            ans = i;
        }
    }
    cout << ans << "\n";
    return (0);
}
