#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
// 3点解答
int main()
{
	ll t, n, s, e, m1, m2, vm1, vm2;
	cin >> t;
	REP(i, t)
	{
		cin >> n;
		if (n == 1)
		{

			{
				cout << "? 1" << endl;
				cin >> s;
				cout << "! " << s << endl;
			}
		}
		else if (n == 2)
		{

			cout << "? 1" << endl;
			cin >> s;
			cout << "? 2" << endl;
			cin >> e;
			cout << "! " << max(s, e) << endl;
		}
		else
		{

			vector<ll> a(n + 1, -1);
			s = 1;
			e = n;
			while (e - s > 1)
			{
				m1 = (e + s * 2) / 3;
				m2 = (s + e * 2) / 3;
				if (a[m1] != -1)
				{
					vm1 = a[m1];
				}
				else
				{
					cout << "? " << m1 << endl;
					cin >> vm1;
					a[m1] = vm1;
				}
				if (a[m2] != -1)
				{
					vm2 = a[m2];
				}
				else
				{
					cout << "? " << m2 << endl;
					cin >> vm2;
					a[m2] = vm2;
				}
				if (vm1 < vm2)
				{
					s = m1 + 1;
				}
				if (vm1 > vm2)
				{
					e = m2 - 1;
				}
				if (vm1 == vm2)
				{
					s = m1 + 1;
					e = m2 - 1;
				}

				// cout << "s" << s << " e" << e << endl;
			}
			if (a[e] == -1 && a[e - 1] != -1)
			{
				cout << "? " << e << endl;
				cin >> vm1;
				a[e] = vm1;
			}
			if (a[s] == -1 && a[s + 1] != -1)
			{
				cout << "? " << s << endl;
				cin >> vm1;
				a[s] = vm1;
			}
			REP(i, n)
			{
				if (a[i] > a[i + 1] && a[i + 1] != -1 && a[i] != -1)
				{
					cout << "! " << a[i] << endl;
					break;
				}
				if (i == n - 1)
					cout << "! " << a[i + 1] << endl;
			}
		}
	}
	return (0);
}
// vm1<vm2  vm+1~ <<<<10>9>>>>
// vm>vm2   ~vm-1
//   1 2 3 4 5 6 5 4 3 2 10 1 4321
// 1 3 13 12  11...1
// 1 3 5 7 9 11 13 15 13 124321