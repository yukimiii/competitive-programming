#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n = 20;
	ll ans = 0;
	vector<vector<ll>> vv(n, vector<ll>(n));
	REP(i, n)
	{
		REP(j, n)
		{
			cin >> vv[i][j];
		}
	}
	ll tmp = 0;
	REP(i, 17)
	{
		REP(j, 17)
		{
			tmp = vv[i][j] * vv[i + 1][j + 1] * vv[i + 2][j + 2] * vv[i + 3][j + 3];
		};
		ans = max(ans, tmp);
	}
	REP(i, 17)
	{
		REP(j, 17)
		{
			tmp = vv[19 - i][j] * vv[18 - i][j + 1] * vv[17 - i][j + 2] * vv[16 - i][j + 3];
		};
		ans = max(ans, tmp);
	}
	REP(i, 20)
	{
		REP(j, 17)
		{
			tmp = vv[i][j] * vv[i][j + 1] * vv[i][j + 2] * vv[i][j + 3];
		};
		ans = max(ans, tmp);
	}
	REP(j, 20)
	{
		REP(i, 17)
		{
			tmp = vv[i][j] * vv[i + 1][j] * vv[i + 2][j] * vv[i + 3][j];
		};
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return (0);
}
