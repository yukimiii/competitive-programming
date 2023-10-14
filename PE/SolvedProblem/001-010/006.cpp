#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans;
    ans = (n - 1) * n * (n + 1) * (3 * n + 2) / 12;
    cout << ans << "\n";
    return (0);
}
