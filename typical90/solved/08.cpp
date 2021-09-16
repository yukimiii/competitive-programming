#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[100009][8];
int main()
{
	ll n;
	string s;
	cin >> n >> s;
	dp[0][0] = 1;
	for (int i = 0; i < (int)s.size(); i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			dp[i + 1][j] += dp[i][j];
			if (s[i] == 'a' && j == 0)
				dp[i + 1][j + 1] += dp[i][j];
			if (s[i] == 't' && j == 1)
				dp[i + 1][j + 1] += dp[i][j];
			if (s[i] == 'c' && j == 2)
				dp[i + 1][j + 1] += dp[i][j];
			if (s[i] == 'o' && j == 3)
				dp[i + 1][j + 1] += dp[i][j];
			if (s[i] == 'd' && j == 4)
				dp[i + 1][j + 1] += dp[i][j];
			if (s[i] == 'e' && j == 5)
				dp[i + 1][j + 1] += dp[i][j];
			if (s[i] == 'r' && j == 6)
				dp[i + 1][j + 1] += dp[i][j];
		}
		for (int j = 0; j <= 7; j++)
			dp[i + 1][j] %= mod;
	}
	cout << dp[n][7] % mod << endl;
	return (0);
}
