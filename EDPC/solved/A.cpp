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
ll dp[100010];

int main()
{
	cin >> n;
	vector<ll> a(n + 1);
	REP(i, n) { cin >> a[i + 1]; }
	dp[2] = abs(a[2] - a[1]);
	FOR(i, 3, n + 1)
	{
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << dp[n] << endl;
	return (0);
}
