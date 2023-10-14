#include <bits/stdc++.h>
using namespace std;

int main()
{
    int forward1;
    int forward2;
    int ans;
    int val;
    forward1 = 2;
    forward2 = 1;
    val = 0;
    ans = 2;
    while (val < 4000000)
    {
        if (val % 2 == 0)
        {
            ans += val;
        }
        val = forward1 + forward2;
        forward2 = forward1;
        forward1 = val;
    }
    cout << ans << '\n';
    return (0);
}
