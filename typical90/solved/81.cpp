#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	vector<vector<int>> table(5010, vector<int>(5010));
	ll n, k;
	cin >> n >> k;
	REP(i, n)
	{
		int a, b;
		cin >> a >> b;
		table[a][b]++;
	}
	REP(i, 5001)
	{
		REP(j, 5001)
		{
			table[i + 1][j] += table[i][j];
		}
	}
	REP(i, 5001)
	{
		REP(j, 5001)
		{
			table[i][j + 1] += table[i][j];
		}
	}

	int ans = 0;
	REP(i, 5001 - k)
	{
		REP(j, 5001 - k)
		{
			ans = max(ans, table[i + k + 1][j + k + 1] + table[i][j] - table[i][j + k + 1] - table[i + k + 1][j]);
		}
	}
	cout << ans << endl;
	return (0);
}
