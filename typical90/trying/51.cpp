#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll t, n, s, e, m1, m2, vm1, vm2;
	cin >> t >> n;
	REP(i, t)
	{
		s = 0;
		e = n - 1;
		while (e - s > 1)
		{
			m1 = (e - s) / 3;
			m2 = (e - s) / 3 * 2;
			cout << "? " << m1 << endl;
			cin >> vm1;
			cout << "? " << m2 << endl;
			cin >> vm2;
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
		}
		cout << "! " << max(vm1, vm2) << endl;
	}

	return (0);
}
// vm1<vm2  vm+1~ <<<<10>9>>>>
// vm>vm2   ~vm-1