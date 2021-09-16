#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main()
{
	ll n;
	cin >> n;
	Graph G(n);
	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	// BFS のためのデータ構造
	vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
	queue<int> que;

	// 初期条件 (頂点 0 を初期ノードとする)
	dist[0] = 0;
	que.push(0); // 0 を橙色頂点にする

	// BFS 開始 (キューが空になるまで探索を行う)
	while (!que.empty())
	{
		int v = que.front(); // キューから先頭頂点を取り出す
		que.pop();

		// v から辿れる頂点をすべて調べる
		for (int nv : G[v])
		{
			if (dist[nv] != -1)
				continue; // すでに発見済みの頂点は探索しない

			// 新たな白色頂点 nv について距離情報を更新してキューに追加する
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}
	vector<int> odd;
	vector<int> even;
	int oddcnt = 0, evcnt = 0;

	REP(i, n)
	{
		if (dist[i] % 2)
		{
			odd.push_back(i);
			oddcnt++;
		}
		else
		{
			even.push_back(i);
			evcnt++;
		}
		if (oddcnt == n / 2)
		{
			REP(i, n / 2 - 1)
			cout << odd[i] + 1 << " ";
			cout << odd[n / 2 - 1] + 1 << endl;
			return 0;
		}
		if (evcnt == n / 2)
		{
			REP(i, n / 2 - 1)
			cout << even[i] + 1 << " ";
			cout << even[n / 2 - 1] + 1 << endl;
			return 0;
		}
	}
	return (0);
}
