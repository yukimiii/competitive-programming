#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
int main()
{
	int n, q;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	sort(a.begin(), a.end());
	cin >> q;
	vector<ll> b(q);
	REP(i, q)
	{
		cin >> b[i];
	}
	REP(i, q)
	{
		int index = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		if (index >= 1 && index < n)
			cout << min(a[index] - b[i], b[i] - a[index - 1]) << endl;
		if (index == 0)
			cout << a[index] - b[i] << endl;
		if (index == n)
			cout << b[i] - a[index - 1] << endl;
	}
	return (0);
}
