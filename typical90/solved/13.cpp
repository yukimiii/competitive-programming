#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000
struct edge
{
	ll to, cost;
};
typedef pair<ll, ll> P;
// 双方向のときはどっちもadd edgeする
struct graph
{
	ll V;
	vector<vector<edge>> G;
	vector<ll> d;

	graph(ll n)
	{
		init(n);
	}

	void init(ll n)
	{
		V = n;
		G.resize(V);
		d.resize(V);
		REP(i, V)
		{
			d[i] = INF;
		}
	}

	void add_edge(ll s, ll t, ll cost)
	{
		edge e;
		e.to = t, e.cost = cost;
		G[s].push_back(e);
	}

	void dijkstra(ll s)
	{
		REP(i, V)
		{
			d[i] = INF;
		}
		d[s] = 0;
		priority_queue<P, vector<P>, greater<P>> que;
		que.push(P(0, s));
		while (!que.empty())
		{
			P p = que.top();
			que.pop();
			ll v = p.second;
			if (d[v] < p.first)
				continue;
			for (auto e : G[v])
			{
				if (d[e.to] > d[v] + e.cost)
				{
					d[e.to] = d[v] + e.cost;
					que.push(P(d[e.to], e.to));
				}
			}
		}
	}
};
int main()
{
	ll n, m;
	cin >> n >> m;
	ll a, b, c;
	graph g(n);
	REP(i, m)
	{
		cin >> a >> b >> c;
		g.add_edge(a - 1, b - 1, c);
		g.add_edge(b - 1, a - 1, c);
	}
	vector<ll> fromstart(n);
	vector<ll> fromend(n);
	g.dijkstra(0);
	REP(i, n)
	{
		fromstart[i] = g.d[i];
		// cout << g.d[i] << endl;
	}
	// g.init(n);
	g.dijkstra(n - 1);
	REP(i, n)
	{
		fromend[i] = g.d[i];
		// cout << g.d[i] << endl;
	}
	REP(i, n)
	{
		cout << fromstart[i] + fromend[i] << endl;
	}
	return (0);
}
