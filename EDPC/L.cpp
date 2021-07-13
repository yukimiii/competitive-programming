#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
#define all(c) ((c).begin()), ((c).end())

using namespace std;
typedef long long ll;
const static ll MOD = 998244353;
const static ll mod = 1000000007;
const static ll inf = 1000000000000;

ll ans, n, m, h, w, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

long long modify(ll a, ll m)
{
	a %= m;
	if (a < 0)
	{
		a += m;
	}
	return a;
}
int main()
{
	cin >> n;
	return (0);
}
