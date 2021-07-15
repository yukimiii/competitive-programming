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

ll dp[110][100010];
int main()
{
	REP(i, 110)
	{
		REP(j, 100010)
		dp[i][j] = inf;
	}
	// 重さを加算するdpデーブル
	cin >> n >> w;
	vector<ll> a(n), b(n);
	REP(i, n) { cin >> a[i] >> b[i]; }
	dp[1][b[0]] = a[0];
	REP(i, n)
	{
		REP(j, 100010)
		{
			dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
			if (dp[i][j] + a[i] <= w)
			{
				dp[i + 1][j + b[i]] = min(dp[i][j] + a[i], dp[i + 1][j + b[i]]);
			}
		}
	}
	ans = 0;
	for (int i = 100000; i >= 0; i--)
	{
		REP(j, n + 1)
		{
			if (dp[j + 1][i] != inf)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	return (0);
}
