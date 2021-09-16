#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	vector<ll> a(n), b(n);
	REP(i, n) { cin >> a[i] >> b[i]; }
	vector<ll> c(2 * n);
	REP(i, n)
	{
		c[i] = b[i];
		c[i + n] = a[i] - b[i];
	}
	sort(c.begin(), c.end(), greater<ll>());
	REP(i, k)
	{
		ans += c[i];
	}
	cout << ans << endl;
	return (0);
}
