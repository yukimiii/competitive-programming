#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	vector<vector<int>> dp(110, vector<int>(100010));
	int n, s;
	string ans = "";
	cin >> n >> s;
	vector<ll> a(n), b(n);
	REP(i, n) { cin >> a[i] >> b[i]; }
	dp[0][0] = 1;
	REP(i, n)
	{
		REP(j, 100010)
		{
			if (j + a[i] <= 100000)
				dp[i + 1][j + a[i]] += dp[i][j];
			if (j + b[i] <= 100000)
				dp[i + 1][j + b[i]] += dp[i][j];
		}
	}
	if (dp[n][s])
	{
		for (; n >= 1; n--)
		{

			if (s - a[n - 1] >= 0 && dp[n - 1][s - a[n - 1]])
			{
				ans = 'A' + ans;
				s -= a[n - 1];
			}
			else
			{
				ans = 'B' + ans;
				s -= b[n - 1];
			}
		}
		cout << ans << endl;
	}
	else
		cout << "Impossible" << endl;
	return (0);
}
