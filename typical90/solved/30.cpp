#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, k, ans = 0;
	cin >> n >> k;
	ll primecnt[n + 1] = {};
	FOR(i, 2, n + 1)
	{
		if (primecnt[i] >= 1)
			continue;
		for (int j = i; j <= n; j += i)
		{
			primecnt[j]++;
		}
	}
	REP(i, n + 1)
	{
		if (primecnt[i] >= k)
			ans++;
	}
	cout << ans << endl;
	return (0);
}
