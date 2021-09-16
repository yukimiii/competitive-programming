#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
// いまいち自力でできてない
ll modpow(ll a, ll b, ll m)
{
	ll p = 1, q = a;
	REP(i, 63)
	{
		if ((b & (1LL << i)) != 0)
		{
			p *= q;
			p % m;
		}

		q *= q;
		q %= m;
	}
	return p;
}
int main()
{
	ll n, b, k;
	cin >> n >> b >> k;
	vector<ll> a(k + 1);
	REP(i, k) { cin >> a[i + 1]; }
	ll power10[64];
	ll ans[64][1010];
	ll dp[64][1010];
	REP(i, 63)
	{
		power10[i] = modpow(10LL, (1LL << i), b);
	}
	FOR(i, 1, k + 1)
	{
		dp[0][a[i] % b]++;
	}
	REP(i, 62)
	{
		REP(j, b)
		{
			REP(k, b)
			{
				int nex = (j * power10[i] + k) % b;
				dp[i + 1][nex] += dp[i][j] * dp[i][k];
				dp[i + 1][nex] %= mod;
			}
		}
	}
	ans[0][0] = 1;
	REP(i, 62)
	{
		if ((n & (1LL << i)) != 0LL)
		{
			REP(j, b)
			{
				REP(k, b)
				{
					int nex = (j * power10[i] + k) % b;
					ans[i + 1][nex] += ans[i][j] * dp[i][k];
					ans[i + 1][nex] %= mod;
				}
			}
		}
		else
		{
			REP(j, b)
			{
				ans[i + 1][j] = ans[i][j];
			}
		}
	}
	cout << ans[62][0] << endl;
	return (0);
}
