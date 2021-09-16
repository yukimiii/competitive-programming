#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<vector<ll>> vv(n, vector<ll>(n));
	REP(i, n)
	{
		REP(j, n) { cin >> vv[i][j]; }
	}
	int m;
	cin >> m;
	int re[n][n] = {};
	REP(i, m)
	{
		int a, b;
		cin >> a >> b;
		re[min(a, b) - 1][max(a, b) - 1]++;
	}
	ll ans = 1000000000000;
	int len = n;
	vector<int> vec(len);
	for (int i = 0; i < len; i++)
		vec[i] = i;
	do
	{
		ll tmp = 0;
		for (int i = 0; i < len; i++)
		{
			if (i != n - 1)
				if (re[vec[i + 1]][vec[i]] || re[vec[i]][vec[i + 1]])
					break;
			// cout << vv[vec[i]][i] << endl;
			tmp += vv[vec[i]][i];
			if (i == n - 1)
			{
				// cout << tmp << endl;
				ans = min(ans, tmp);
			}
		}

	} while (next_permutation(vec.begin(), vec.end()));
	if (ans == 1000000000000)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return (0);
}
