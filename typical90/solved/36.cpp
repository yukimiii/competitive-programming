#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, q, x, y, maxx = -100000000, maxy = -100000000, minx = 200000000, miny = 2000000000;

	cin >> n >> q;
	vector<ll> a(n), b(n);
	REP(i, n)
	{
		cin >> a[i] >> b[i];
		x = a[i] + b[i];
		y = a[i] - b[i];
		a[i] = x;
		b[i] = y;
		// cout << x << " " << y << endl;
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}
	// cout << maxx << endl;
	REP(i, q)
	{
		int que;
		cin >> que;
		que--;
		cout << max(max(a[que] - minx, maxx - a[que]), max(b[que] - miny, maxy - b[que])) << endl;
	}

	return (0);
}
