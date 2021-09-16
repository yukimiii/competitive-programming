#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, q;
	cin >> n >> q;
	deque<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	REP(i, q)
	{
		ll t, x, y, tmp;
		cin >> t >> x >> y;
		x--;
		y--;
		if (t == 1)
			swap(a[x], a[y]);
		else if (t == 2)
		{
			tmp = a[n - 1];
			a.pop_back();
			a.push_front(tmp);
		}
		else
			cout << a[x] << endl;
	}
	return (0);
}
