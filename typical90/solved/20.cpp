#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

//a c^bの比較　
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll tmp = 1;
	REP(i, b)
	{
		tmp *= c;
		if (tmp > a)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return (0);
}
