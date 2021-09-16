#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	vector<ll> dif(n - 1);
	ll ans = 0;
	REP(i, n - 1)
	{
		dif[i] = a[i + 1] - a[i];
		ans += abs(diff[i]);
	}
	REP(i, q)
	{
		int l, r, v;
		cin >> l >> r >> v;
	}
	return (0);
}
