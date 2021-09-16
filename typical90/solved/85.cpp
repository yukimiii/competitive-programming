#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n)
{
	vector<long long> ret;
	for (long long i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ret.push_back(i);
			if (i * i != n)
				ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end()); // 昇順に並べる
	return ret;
}
// 素因数分解
template <typename T>
map<T, T> prime_factor(T n)
{
	map<T, T> ret;
	for (T i = 2; i * i <= n; i++)
	{
		T tmp = 0;
		while (n % i == 0)
		{
			tmp++;
			n /= i;
		}
		ret[i] = tmp;
	}
	if (n != 1)
		ret[n] = 1;
	return ret;
}
/*  divisor_num(n)
    入力：整数 n
    出力：nの約数の個数
    計算量：O(√n)
*/
template <typename T>
T divisor_num(T N)
{
	map<T, T> pf = prime_factor(N);
	T ret = 1;
	for (auto p : pf)
	{
		ret *= (p.second + 1);
	}
	return ret;
}

int main()
{
	ll k;
	cin >> k;
	ll r = 0, ans = 0;
	while (r * r * r < k)
	{
		r++;
	}
	// if (r * r * r == k)
	// 	ans++;
	vector<ll> v = divisor(k);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= r)
		{
			// cout << v[i] << " " << k / v[i] << endl;
			ll ab = k / v[i];
			vector<ll> vv = divisor(ab);
			// cout << vv.size() << endl;
			int minus = 0;
			for (int j = vv.size() - 1; j >= 0; j--)
			{
				if (vv[j] > v[i])
					minus++;
				else
					break;
			}
			ans += (divisor_num(ab) + 1) / 2 - minus;
		}
	}

	cout << ans << endl;
	return (0);
}
