#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
// 黄金分割探索
int fib[16] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};
int idx[1609];

int ask(int pos)
{
	if (idx[pos] == -1)
	{
		cout << "? " << pos << endl;
		int t;
		cin >> t;
		idx[pos] = t;
	}
	return idx[pos];
}

void solve(int n)
{
	int ans = 0;
	// idx初期化
	for (int i = 0; i <= n; i++)
		idx[i] = -1;
	for (int i = n + 1; i <= 1600; i++)
		idx[i] = -i;
	if (n <= 5)
	{
		for (int i = 1; i <= n; i++)
			ans = max(ans, ask(i));
	}
	else
	{
		int cl = 0, cr = 1597, dl = 610, dr = 987;
		int el = ask(dl);
		int er = ask(dr);
		for (int i = 13; i >= 0; i--)
		{
			if (dl == -1)
			{
				dl = cl + fib[i];
				el = ask(dl);
			}
			else if (dr == -1)
			{
				dr = cr - fib[i];
				er = ask(dr);
			}
			ans = max({ans, el, er});
			if (el < er)
			{
				cl = dl;
				dl = dr;
				dr = -1;
				el = er;
				er = -1;
			}
			else
			{
				cr = dr;
				dr = dl;
				dl = -1;
				er = el;
				el = -1;
			}
		}
		for (int i = cl + 1; i <= cr - 1; i++)
			ans = max(ans, ask(i));
	}

	cout << "! " << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	REP(i, t)
	{
		int n;
		cin >> n;
		solve(n);
	}
	return (0);
}
// vm1<vm2  vm+1~ <<<<10>9>>>>
// vm>vm2   ~vm-1
//   1 2 3 4 5 6 5 4 3 2 10 1 4321
// 1 3 13 12  11...1
// 1 3 5 7 9 11 13 15 13 124321