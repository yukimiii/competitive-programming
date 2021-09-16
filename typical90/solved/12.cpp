#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
/* UnionFind：素集合系管理の構造体(union by size)
    isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
    treeSize(x): x を含む集合の要素数。
*/
struct UnionFind
{
	vector<int> size, parents;
	UnionFind() {}
	UnionFind(int n)
	{ // make n trees.
		size.resize(n, 0);
		parents.resize(n, 0);
		for (int i = 0; i < n; i++)
		{
			makeTree(i);
		}
	}
	void makeTree(int x)
	{
		parents[x] = x; // the parent of x is x
		size[x] = 1;
	}
	bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
	bool unite(int x, int y)
	{
		x = findRoot(x);
		y = findRoot(y);
		if (x == y)
			return false;
		if (size[x] > size[y])
		{
			parents[y] = x;
			size[x] += size[y];
		}
		else
		{
			parents[x] = y;
			size[y] += size[x];
		}
		return true;
	}
	int findRoot(int x)
	{
		if (x != parents[x])
		{
			parents[x] = findRoot(parents[x]);
		}
		return parents[x];
	}
	int treeSize(int x) { return size[findRoot(x)]; }
};

// グループ数える関数
int countTree(UnionFind tree, int n)
{
	set<int> group;
	REP(i, n)
	{
		group.insert(tree.findRoot(i));
	}
	return (group.size());
}
int main()
{
	int h, w;
	ll q;
	int t;
	cin >> h >> w >> q;
	int x, y;
	int x2, y2;
	vector<vector<ll>> hw(h, vector<ll>(w));
	UnionFind tree(h * w);
	REP(i, q)
	{
		cin >> t;
		if (t == 1)
		{
			cin >> x >> y;
			x--;
			y--;
			hw[x][y] = 1;
			if (x > 0 && hw[x - 1][y])
			{
				tree.unite(w * x + y, w * (x - 1) + y);
			}
			if (y > 0 && hw[x][y - 1])
			{
				tree.unite(w * x + y, w * x + y - 1);
			}
			if (x < h - 1)
			{
				if (hw[x + 1][y])
					tree.unite(w * x + y, w * (x + 1) + y);
			}
			if (y < w - 1)
			{
				if (hw[x][y + 1])
					tree.unite(w * x + y, w * x + y + 1);
			}
		}
		if (t == 2)
		{
			cin >> x >> y >> x2 >> y2;
			x--;
			y--;
			x2--;
			y2--;
			if (tree.isSame(w * x + y, w * x2 + y2) && hw[x])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return (0);
}
