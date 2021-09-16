#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int q;
	deque<int> card;
	cin >> q;
	vector<ll> t(q), x(q);
	REP(i, q) { cin >> t[i] >> x[i]; }
	REP(i, q)
	{
		if (t[i] == 1)
			card.push_front(x[i]);
		if (t[i] == 2)
			card.push_back(x[i]);
		if (t[i] == 3)
		{
			cout << card[x[i] - 1] << endl;
		}
	}
	return (0);
}
