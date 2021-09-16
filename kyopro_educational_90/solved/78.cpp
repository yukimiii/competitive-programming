#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, m, a, b;
	ll ans = 0;
	cin >> n >> m;
	vector<ll> count(100001);
	REP(i, m)
	{
		cin >> a >> b;
		count[max(a, b)]++;
	}
	REP(i, 100001)
	{
		if (count[i] == 1)
			ans++;
	}
	cout << ans << endl;
	return (0);
}
