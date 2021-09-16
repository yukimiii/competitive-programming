#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	ll n, l;
	cin >> n >> l;
	ll dp[n + l + 1] = {};
	dp[0] = 1;

	REP(i, n)
	{
		dp[i + 1] += dp[i] % mod;
		dp[i + l] += dp[i] % mod;
	}
	cout << dp[n] % mod << endl;
	return (0);
}
