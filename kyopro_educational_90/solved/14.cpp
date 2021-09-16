#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll ans = 0;
	vector<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	vector<ll> b(n);
	REP(i, n) { cin >> b[i]; }
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	REP(i, n)
	{
		ans += abs(a[i] - b[i]);
	}
	cout << ans << endl;
	return (0);
}
