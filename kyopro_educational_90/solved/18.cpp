#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
double pi = 3.14159265358979;
int main()
{
	long double t, l, x, y;
	cin >> t >> l >> x >> y;
	int q;
	cin >> q;
	long double yy;
	long double zz;
	long double d1;
	long double d2;
	vector<long double> a(q);
	REP(i, q)
	{
		cin >> a[i];

		yy = -1 * l * sin(pi * 2 * a[i] / t) / 2;
		zz = l / 2 - l * cos(pi * 2 * a[i] / t) / 2;
		d1 = sqrt(x * x + (y - yy) * (y - yy));
		d2 = zz;
		cout << setprecision(12) << atan2(d2, d1) * 180 / pi << endl;
	}
	return (0);
}
