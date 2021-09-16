#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	map<string, int> mp;
	string s;
	REP(i, n)
	{
		cin >> s;
		if (mp[s] == 0)
			cout << i << endl;
		mp[s] = 1;
	}

	return (0);
}
