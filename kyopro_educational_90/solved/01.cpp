#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, l, k, div;
	cin >> n >> l >> k;
	int tmp;
	vector<ll> a(n + 2);
	a[0] = 0;
	a[n + 1] = l;
	REP(i, n)
	{
		cin >> a[i + 1];
	}
	ll left = 1;
	ll right = l + 1;
	while (right - left > 1)
	{
		ll mid = (left + right) / 2;
		// cout << mid << endl;
		int j = 0;
		int count = 0;
		int tmp = 0;
		while (j <= n)
		{
			tmp += a[j + 1] - a[j];
			if (tmp >= mid)
			{
				// cout << "tmp" << tmp << endl;
				count++;
				tmp = 0;
			}
			j++;
		}
		if (count > k)
			left = mid;
		else
			right = mid;
	}
	cout << left << endl;
	return (0);
}