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
ll dp[100010][3];

int main()
{
	cin >> n;
	ll happiness[n][3];
	REP(i, n) { cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2]; }
	REP(i, n)
	{
		REP(j, 3)
		{
			dp[i + 1][j] = max(dp[i][(j + 1) % 3] + happiness[i][(j + 1) % 3], dp[i][(j + 2) % 3] + happiness[i][(j + 2) % 3]);
		}
	}
	ll ans = 0;
	REP(i, 3)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	return (0);
}
