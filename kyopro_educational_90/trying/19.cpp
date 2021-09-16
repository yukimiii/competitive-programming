#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

ll dp[410][410];
int main()
{
	int n;
	cin >> n;
	vector<ll> a(2 * n + 1);
	REP(i, 2 * n) { cin >> a[i + 1]; }
	FOR(l, 1, 2 * n + 1)
	{
		FOR(r, l + 1, 2 * n + 1)
		{
			dp[l][r] = 10000000000;
			if (r == l + 1)
				dp[l][r] = abs(a[r] - a[l]);
		}
	}

	cout << dp[2][5] << endl;
	cout << dp[1][2 * n] << endl;
	return (0);
}
