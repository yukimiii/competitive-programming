#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

bool chkline(string s)
{
	int count = 0;
	REP(i, s.length())
	{
		if (s[i] == '(')
			count++;
		if (s[i] == ')')
			count--;
		if (count < 0)
			return (false);
	}
	if (count == 0)
		return (true);
	return (false);
}
int main()
{
	ll n;
	cin >> n;
	if (n % 2 == 0)
	{
		for (int i = 0; i < (1 << n); i++)
		{
			string s = "";
			for (int j = n - 1; j >= 0; j--)
			{

				if ((i & (1 << j)) == 0)
				{
					s += "(";
				}
				else
				{
					s += ")";
				}
			}
			if (chkline(s))
				std::cout << s << endl;
		}
	}
	else
		cout << endl;
	return (0);
}
