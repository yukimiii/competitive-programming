#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
vector<int> g[1 << 18];
const ll INF = 100000000000;

ll dist[1 << 18];
// 深さ優先探索
void getdist(ll s, ll n)
{
	REP(i, n + 1)
	{
		dist[i] = INF;
		// cout << dist[i];
	}
	queue<ll> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		for (int to : g[pos])
		{
			// cout << pos << " " << to << endl;
			if (dist[to] == INF)
			{
				dist[to] = dist[pos] + 1;
				q.push(to);
				// cout << s << " " << to << " " << dist[to] << endl;
			}
		}
	}
}

int main()
{
	ll n;
	cin >> n;
	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// cout << g[2][1] << endl;
	// from1
	getdist(1, n);
	int maxto = -1, maxd = -1;
	FOR(i, 1, n + 1)
	{
		if (maxd < dist[i])
		{
			maxd = dist[i];
			maxto = i;
		}
	}
	// cout << maxd;
	// frommaxto
	getdist(maxto, n);
	FOR(i, 1, n + 1)
	{
		if (maxd < dist[i])
			maxd = dist[i];
	}
	cout << maxd + 1 << endl;
	return (0);
}
