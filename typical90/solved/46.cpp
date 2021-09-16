#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll ans = 0;
	ll ac[46] = {};
	ll bc[46] = {};
	ll cc[46] = {};
	vector<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	vector<ll> b(n);
	REP(i, n) { cin >> b[i]; }
	vector<ll> c(n);
	REP(i, n) { cin >> c[i]; }
	REP(i, n)
	{
		ac[a[i] % 46]++;
		bc[b[i] % 46]++;
		cc[c[i] % 46]++;
	}
	REP(i, 46)
	{
		REP(j, 46)
		{
			REP(k, 46)
			{
				if ((i + j + k) % 46 == 0)
					ans += ac[i] * bc[j] * cc[k];
			}
		}
	}
	cout << ans << endl;
	return (0);
}
