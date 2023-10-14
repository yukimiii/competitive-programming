#include <bits/stdc++.h>
using namespace std;

long long combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combination(n, r - 1) * (n - r + 1) / r;
}
int main()
{
    int i;
    int j;
    cin >> i >> j;
    cout << combination(i + j, i) << "\n";
    return (0);
}
