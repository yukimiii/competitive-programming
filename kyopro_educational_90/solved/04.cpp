#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll h, w;
	cin >> h >> w;
	vector<vector<ll>> hw(h, vector<ll>(w));
	REP(i, h)
	{
		REP(j, w) { cin >> hw[i][j]; }
	}
	ll sumh[h] = {};
	ll sumw[w] = {};
	REP(i, h)
	{
		REP(j, w)
		{
			sumh[i] += hw[i][j];
		}
	}
	REP(i, h)
	{
		REP(j, w)
		{
			sumw[j] += hw[i][j];
		}
	}
	REP(i, h)
	{
		REP(j, w)
		{
			cout << sumh[i] + sumw[j] - hw[i][j] << " ";
		}
		cout << endl;
	}
	return (0);
}
