#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
template <typename T>
vector<int> offline_dag_reachability(const Graph<T> &g, vector<pair<int, int>> &qs)
{
	const int N = (int)g.size();
	const int Q = (int)qs.size();
	auto ord = topological_sort(g);
	vector<int> ans(Q);
	for (int l = 0; l < Q; l += 64)
	{
		int r = min(Q, l + 64);
		vector<int64_t> dp(N);
		for (int k = l; k < r; k++)
		{
			dp[qs[k].first] |= int64_t(1) << (k - l);
		}
		for (auto &idx : ord)
		{
			for (auto &to : g.g[idx])
				dp[to] |= dp[idx];
		}
		for (int k = l; k < r; k++)
		{
			ans[k] = (dp[qs[k].second] >> (k - l)) & 1;
		}
	}
	return ans;
}
int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, int>> quer;
	return (0);
}
