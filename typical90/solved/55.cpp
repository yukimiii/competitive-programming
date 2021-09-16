#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	ll tmp;
	ll p, q, ans = 0;
	cin >> n >> p >> q;
	vector<ll> a(n);
	REP(i, n)
	{
		cin >> tmp;
		a[i] = tmp % p;
	}
	REP(i, n - 4)
	{
		FOR(j, i + 1, n - 3)
		{
			FOR(k, j + 1, n - 2)
			{
				FOR(l, k + 1, n - 1)
				{

					FOR(m, l + 1, n)
					{
						tmp = a[i];
						tmp = tmp * a[j] % p;
						tmp = tmp * a[k] % p;
						tmp = tmp * a[l] % p;
						tmp = (tmp * a[m]) % p;
						if (tmp % p == q)
						{
							// cout << 360 % p << endl;
							// cout << a[i] * a[j] * a[k] * a[l] * a[m] << endl;
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return (0);
}
