#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int h, w;
	cin >> h >> w;
	if (h < 2 || w < 2)
	{
		cout << h * w << endl;
		return (0);
	}
	if (h == 2 && w == 2)
	{
		cout << 4 << endl;
		return (0);
	}
	cout << (h + 1) / 2 * ((w + 1) / 2) << endl;
	return (0);
}
