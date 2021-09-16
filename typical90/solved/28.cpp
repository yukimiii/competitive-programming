#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, lx, ly, rx, ry;

	cin >> n;
	int f[1001][1001] = {};
	REP(i, n)
	{
		cin >> lx >> ly >> rx >> ry;
		f[lx][ry]--;
		f[rx][ly]--;
		f[lx][ly]++;
		f[rx][ry]++;
	}
	REP(i, 1000)
	{
		REP(j, 1000)
		{
			f[j + 1][i] += f[j][i];
		}
	}
	REP(i, 1000)
	{
		REP(j, 1000)
		{
			f[i][j + 1] += f[i][j];
		}
	}
	int count[n + 1] = {};
	REP(i, 1000)
	{
		REP(j, 1000)
		{
			count[f[i][j]]++;
		}
	}
	FOR(i, 1, n + 1)
	{
		cout << count[i] << endl;
	}
	return (0);
}
