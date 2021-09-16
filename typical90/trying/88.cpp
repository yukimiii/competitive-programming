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
	vector<ll> x(n), y(n);
	REP(i, n) { cin >> x[i] >> y[i]; }
	return (0);
}
