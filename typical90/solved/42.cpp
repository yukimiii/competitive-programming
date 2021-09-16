#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	ll k;
	cin >> k;
	ll tmp;
	vector<ll> dp(k + 1);
	dp[0] = 1;
	ll ans = 0;
	if (k % 9)
		cout << 0 << endl;
	else
	{
		REP(i, k + 1)
		{
			int b = min(i, 9);
			FOR(j, 1, b + 1)
			{
				dp[i] += dp[i - j];
				dp[i] = dp[i] % mod;
			}
		}
		cout << dp[k] << endl;
	}
	return (0);
}
