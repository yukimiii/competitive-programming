#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);
	REP(i, m)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}
	vector<vector<int>> dist(n, vector<int>(m, -1)); // 全頂点を「未訪問」に初期化
	queue<int> que;
	// 初期条件 (頂点 0 を初期ノードとする)
	REP(i, n)
	{
		dist[i][i] = 0;
		que.push(0); // 0 を橙色頂点にする
					 // BFS 開始 (キューが空になるまで探索を行う)
		while (!que.empty())
		{
			int v = que.front(); // キューから先頭頂点を取り出す
			que.pop();

			// v から辿れる頂点をすべて調べる
			for (int nv : g[v])
			{
				if (dist[i][nv] != -1)
					continue; // すでに発見済みの頂点は探索しない

				// 新たな白色頂点 nv について距離情報を更新してキューに追加する
				dist[i][nv] = dist[i][v] + 1;
				que.push(nv);
			}
		}
	}

	return (0);
}
