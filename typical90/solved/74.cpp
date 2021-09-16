#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	ll ans = 0;
	ll pow2 = 1;
	REP(i, n)
	{
		if (s[i] == 'b')
			ans += pow2;
		if (s[i] == 'c')
			ans += 2 * pow2;
		pow2 *= 2;
	}
	cout << ans << endl;
	return (0);
}
