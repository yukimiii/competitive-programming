#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

ll to_ten(string numstr, int base)
{
	ll ret = 0;
	REP(i, numstr.size())
	{
		ret = ret * base + int(numstr[i] - '0');
	}
	return (ret);
}
string to_base(ll num, int base)
{
	string ret = "";
	while (num)
	{
		ret = char('0' + num % base) + ret;
		num /= base;
	}
	return (ret);
}
string eighttofive(string s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '8')
			s[i] = '5';
		i++;
	}
	return (s);
}
int main()
{
	ll k;
	string n;
	ll tmp;
	cin >> n >> k;
	if (n == "0")
	{
		cout << 0 << endl;
		return (0);
	}
	REP(i, k)
	{
		tmp = to_ten(n, 8);
		n = to_base(tmp, 9);
		n = eighttofive(n);
	}
	cout << n << endl;
	return (0);
}
