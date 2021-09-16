#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	int n, q;
	cin >> n >> q;
	int flag[61][n];
	REP(j, n)
	{
		REP(i, 61)
		{
			flag[i][j] = 1;
		}
	}
	int a[61][q][3];
	REP(i, 61)
	{
		REP(j, q)
		{
			REP(k, 3)
			{
				a[i][j][k] = 0;
			}
		}
	}
	ll w[q];
	REP(i, q)
	{
		ll x, y, z;
		cin >> x >> y >> z >> w[i];
		// cout << bs[0] << endl;
		bitset<60> bs(w[i]);
		REP(j, 60)
		{
			if (bs[j])
			{
				a[j][i][0] = x - 1;
				a[j][i][1] = y - 1;
				a[j][i][2] = z - 1;
			}
			else
			{
				flag[j][x - 1] = 0;
				flag[j][y - 1] = 0;
				flag[j][z - 1] = 0;
			}
		}
	}
	ll ans = 1;
	REP(j, n)
	{
		REP(i, 10)
		{
			cout << flag[i][j];
		}
		cout << endl;
	}
	REP(i, 5)
	{
		int aaa = 0;
		int tmp = 0;
		for (int bit = 0; bit < (1 << n); ++bit)
		{

			// aaa++;
			int fl = 1;
			REP(j, n)
			{
				if (flag[i][j] == 0 && (bit & (1 << j)))
				{
					fl = 0;
					// cout << i << " " << j << endl;
					break;
				}
				else
					cout << i << " " << j << endl;
			}

			if (((bit & (1 << a[i][q][0])) || (bit & (1 << a[i][q][1])) || (bit & (1 << a[i][q][2]))) ==) && fl)
				{
					tmp++;
				}
		}
		// cout << tmp << endl;

		ans *= tmp;
		ans %= mod;
		// cout << ans << endl;
	}
	cout << ans << endl;
	return (0);
}
// 0[1,2,3],3 4
//  1 2 3    110010
// 234       101101
