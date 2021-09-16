#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	vector<ll> abc(3);
	ll n;
	ll ans = 100000000000;
	cin >> n >> abc[0] >> abc[1] >> abc[2];
	sort(abc.begin(), abc.end());
	// cout << abc[0] << " " << abc[1] << " " << abc[2] << n << " " << endl;
	for (int i = 9999; i >= 0; i--)
	{
		for (int j = 9999 - i; j >= 0; j--)
		{
			if ((n - i * abc[2] - j * abc[1]) >= 0 && (n - i * abc[2] - j * abc[1]) % abc[0] == 0)
			{
				ans = min(ans, i + j + (n - i * abc[2] - j * abc[1]) / abc[0]);
			}
		}
	}
	cout << ans << endl;
	return (0);
}
