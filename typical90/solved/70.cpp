#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll xmid;
	ll ymid;
	vector<ll> a(n), b(n);
	REP(i, n)
	{
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	xmid = a[n / 2];
	ymid = b[n / 2];
	ll ans = 0;
	REP(i, n)
	{
		ans += abs(xmid - a[i]) + abs(ymid - b[i]);
	}
	cout << ans << endl;
	return (0);
}
