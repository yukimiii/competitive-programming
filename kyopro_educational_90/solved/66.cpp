#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	ll ten;
	double ans = 0;
	cin >> n;
	vector<ll> l(n), r(n);
	REP(i, n) { cin >> l[i] >> r[i]; }
	REP(i, n - 1)
	{
		FOR(j, i + 1, n)
		{
			ten = 0;
			ll size = (r[i] - l[i] + 1) * (r[j] - l[j] + 1);

			if (r[i] - r[j] > 0 && l[i] <= r[j])
				ten += (r[i] - r[j]) * (r[j] - l[j] + 1);

			if (l[i] > l[j] && l[i] <= r[j])
				ten += (l[i] - l[j]) * (r[i] - l[i] + 1);
			if (r[i] - r[j] > 0 && l[i] > l[j] && l[i] <= r[j])
				ten -= (r[i] - r[j]) * (l[i] - l[j]);
			if (l[i] > r[j])
				ten += size;
			double dupl = max(l[i], l[j]);
			double dupr = min(r[i], r[j]);
			if (dupr > dupl)
				ten += (dupr - dupl) * (dupr - dupl + 1) / 2;
			ans += (double)ten / size;
			// cout << ans << endl;
		}
	}
	cout << setprecision(10) << ans << endl;
	return (0);
}
