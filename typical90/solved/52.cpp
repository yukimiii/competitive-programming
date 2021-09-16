#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()

{
	ll n;
	ll r;
	cin >> n;
	vector<ll> sum(n);
	REP(i, n)
	{
		REP(j, 6)
		{
			cin >> r;
			sum[i] += r;
		}
	}
	ll ans = 1;
	REP(i, n)
	{
		ans *= sum[i];
		ans = ans % mod;
	}
	cout << ans << endl;
	return (0);
}
