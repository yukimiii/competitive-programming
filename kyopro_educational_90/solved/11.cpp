#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

ll dp[5010][5010];
int main()
{
	int n;
	cin >> n;
	vector<ll> d(n + 1), c(n + 1), s(n + 1);
	REP(i, n) { cin >> d[i] >> c[i] >> s[i]; }
	// 締め切り順ソート
	vector<tuple<ll, ll, ll>> task;
	REP(i, n)
	{
		task.push_back(make_tuple(d[i], c[i], s[i]));
		sort(task.begin(), task.end());
	}
	d[0] = 0;
	c[0] = 0;
	s[0] = 0;
	REP(i, n)
	{
		d[i + 1] = get<0>(task[i]);
		c[i + 1] = get<1>(task[i]);
		s[i + 1] = get<2>(task[i]);
	}
	// cout << d[1] << endl;
	REP(i, n)
	{
		REP(j, 5000)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + c[i + 1] <= d[i + 1])
			{
				dp[i + 1][j + c[i + 1]] = max(dp[i + 1][j + c[i + 1]], dp[i][j] + s[i + 1]);
			}
		}
	}
	ll ans = 0;
	// 最後の仕事の終了日ごとにans更新
	REP(i, 5005)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	return (0);
}
