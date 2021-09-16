#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	ll k;
	ll dif = 0;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	REP(i, n) { cin >> a[i]; }
	REP(i, n)
	{
		cin >> b[i];
	}
	REP(i, n)
	{
		dif += abs(a[i] - b[i]);
	}
	if (dif <= k && (k - dif) % 2 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return (0);
}
