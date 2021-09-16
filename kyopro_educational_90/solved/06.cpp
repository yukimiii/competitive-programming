#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n, k;
	string s;
	cin >> n >> k >> s;
	char tmp;
	ll tmpind;
	ll cnt = 0;
	REP(i, k)
	{
		tmp = '{';
		while (cnt <= n - k)
		{
			if (s[cnt] < tmp)
			{
				tmp = s[cnt];
				tmpind = cnt;
			}
			cnt++;
		}
		cout << tmp;
		n++;
		cnt = tmpind + 1;
	}
	cout << endl;
	return (0);
}
