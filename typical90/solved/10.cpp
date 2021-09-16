#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> cl(n);

	REP(i, n)
	{
		cin >> cl[i];
		cin >> a[i];
	}
	vector<ll> asum(n + 1);
	vector<ll> bsum(n + 1);
	asum[0] = 0;
	bsum[0] = 0;
	REP(i, n)
	{

		if (cl[i] == 1)
		{
			asum[i + 1] = asum[i] + a[i];
			bsum[i + 1] = bsum[i];
		}
		if (cl[i] == 2)
		{
			bsum[i + 1] = bsum[i] + a[i];
			asum[i + 1] = asum[i];
		}
		// cout << asum[i + 1] << " " << bsum[i + 1] << endl;
	}
	ll q;
	cin >> q;
	vector<ll> l(q), r(q);
	REP(i, q) { cin >> l[i] >> r[i]; }
	REP(i, q)
	{
		int le = l[i] - 1;
		int ri = r[i];
		cout << asum[ri] - asum[le] << " " << bsum[ri] - bsum[le] << endl;
	}
	return (0);
}