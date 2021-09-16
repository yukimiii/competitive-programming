#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<ll>> a(h, vector<ll>(w));
	REP(i, h)
	{
		REP(j, w) { cin >> a[i][j]; }
	}
	vector<vector<ll>> b(h, vector<ll>(w));
	REP(i, h)
	{
		REP(j, w) { cin >> b[i][j]; }
	}
	ll ans = 0;
	REP(i, h - 1)
	{
		REP(j, w - 1)
		{
			int tmp = a[i][j] - b[i][j];
			ans += abs(tmp);
			REP(k, 2)
			{
				REP(l, 2)
				b[i + k][j + l] += tmp;
			}
		}
	}
	REP(i, h)
	{
		REP(j, w)
		{
			if (a[i][j] != b[i][j])
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	cout << ans << endl;
	return (0);
}
