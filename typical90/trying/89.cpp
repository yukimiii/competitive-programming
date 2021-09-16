#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	vector<ll> order(n);
	REP(i, n)
	{
		order[i] = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
	}
	REP(i, n)
	{
		cout << order[i] << endl;
	}

	return (0);
}
