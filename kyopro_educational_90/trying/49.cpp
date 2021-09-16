#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, m, c, l, r;
	ll ans = 0;
	cin >> n >> m;
	vector<tuple<ll, ll, ll>> item(m);
	REP(i, m)
	{
		cin >> c >> l >> r;
		item[i] = {l, r, c};
	}
	sort(item.begin(), item.end());
	vector<ll> lv(m);
	vector<ll> rv(m);
	vector<ll> cv(m);
	REP(i, m)
	{
		lv[i] = get<0>(item[i]);
		rv[i] = get<1>(item[i]);
		cv[i] = get<2>(item[i]);
		// cout << cv[i] << endl;
	}
	l = 0;
	r = rv[0];
	ll flag;
	ll count;
	REP(i, m)
	{
		vector<ll> costs;
		count = 0;
		flag = 0;
		while (lv[i] <= r)
		{
			if (lv[i] == rv[i])
				flag = 1;
			r = max(r, rv[i]);
			if (i == 0 || (lv[i] != lv[i - 1] || rv[i] != rv[i - 1]))
			{

				costs.emplace_back(cv[i]);
				if (l <= lv[i] && r >= rv[i] && count >= r - l + 1)
				{
					sort(costs.begin(), costs.end());
					costs.pop_back();
				}
				count++;
			}
			i++;
		}
		if (flag == 0 || count < r - l + 1)
		{
			// cout << r << " " << l << " " << flag << endl;
			cout << -1 << endl;
			return (0);
		}
		sort(costs.begin(), costs.end());
		REP(j, r - l)
		{
			cout << costs[j] << endl;
			ans += costs[j];
		}
		l = lv[i];
		r = rv[i];
	}
	cout << ans << endl;
	return (0);
}
// 28 27 89 55 79 88 34 13 27 28