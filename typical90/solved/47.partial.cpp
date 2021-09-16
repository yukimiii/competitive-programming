#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
// n<=2000 OK n<=10^6 NG
int main()
{
	int n;
	string s, t;
	string r, g, b;
	cin >> n;
	cin >> s >> t;
	REP(i, n)
	{
		if (s[i] == 'R')
		{
			r += 'R';
			g += 'B';
			b += 'G';
		}
		else if (s[i] == 'G')
		{
			r += 'B';
			g += 'G';
			b += 'R';
		}
		else if (s[i] == 'B')
		{
			r += 'G';
			g += 'R';
			b += 'B';
		}
	}
	ll ans = 0;
	REP(i, n)
	{
		// cout << t.compare(n - 1 - i, i, r, 0, i) << endl;
		if (t.compare(n - 1 - i, i + 1, r, 0, i + 1) == 0 || t.compare(n - i - 1, i + 1, g, 0, i + 1) == 0 || t.compare(n - i - 1, i + 1, b, 0, i + 1) == 0)
		{

			ans++;
		}
	}
	REP(i, n - 1)
	{
		if (t.compare(0, i + 1, r, n - i - 1, i + 1) == 0 || t.compare(0, i + 1, g, n - i - 1, i + 1) == 0 || t.compare(0, i + 1, b, n - i - 1, i + 1) == 0)
			ans++;
	}

	// cout << r << endl;
	// cout << g << endl;
	// cout << b << endl;
	cout << ans << endl;
	return (0);
}
