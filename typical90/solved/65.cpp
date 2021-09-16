#include <bits/stdc++.h>
#include <atcoder/convolution>

#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
using namespace atcoder;

typedef long long ll;
#define MOD 998244353
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long combination(int n, int k)
{
	if (n < k)
		return 0;
	if (n < 0 || k < 0)
		return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
	COMinit();
	ll ans = 0;
	ll r, g, b, k, x, y, z;
	cin >> r >> g >> b >> k >> x >> y >> z;
	vector<ll> R(k + 1);
	REP(i, k + 1)
	{
		if (k - y <= i && i <= min(k, r))
			R[i] = combination(r, i);
		// cout<<R[i]<<endl;
	}
	vector<ll> G(k + 1);
	REP(i, k + 1)
	{
		if (k - z <= i && i <= min(k, g))
			G[i] = combination(g, i);
	}
	vector<ll> B(k + 1);
	REP(i, k + 1)
	{
		if (k - x <= i && i <= min(k, b))
			B[i] = combination(b, i);
		//cout<<B[i]<<endl;
	}
	vector<ll> GB = atcoder::convolution<998244353>(B, G);
	REP(i, k + 1)
	{
		//cout<<GB[i]<<endl;
		ans += (R[i]) * (GB[k - i]);
		ans = ans % MOD;
	}
	cout << ans << endl;
	return (0);
}