#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

ll calc(ll num)
{
	ll tmp = 0;
	ll ret = num;
	while (num)
	{
		tmp += num % 10;
		num /= 10;
	}
	return (tmp + ret) % 100000;
}
int main()
{
	ll n;
	ll k;
	cin >> n >> k;
	ll index = 1;
	vector<ll> a;

	ll next = calc(n);
	// cout << next << endl;
	ll start = 0;
	a.push_back(next);
	next = calc(next);

	while (index != k)
	{
		if (find(a.begin(), a.end(), next) != a.end())
		{
			start = find(a.begin(), a.end(), next) - a.begin();
			break;
		}
		// cout << next << endl;
		index++;
		a.push_back(next);
		next = calc(next);
	}
	if (index != k)
		cout << a[(k - 1 - start) % (index - start) + start] << endl;
	else
		cout << a[k - 1] << endl;
	return (0);
}
