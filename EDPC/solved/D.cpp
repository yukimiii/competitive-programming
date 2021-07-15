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
	cin >> n >> w;
	vector<ll> a(n), b(n);
	REP(i, n) { cin >> a[i] >> b[i]; }
	REP(i, n)
	{
		REP(j, w)
		{
			dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
			if (a[i] + j <= w)
			{
				dp[i + 1][a[i] + j] = max(dp[i + 1][a[i] + j], dp[i][j] + b[i]);
			}
		}
	}
	ans = 0;
	REP(i, w + 1)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	return (0);
}
