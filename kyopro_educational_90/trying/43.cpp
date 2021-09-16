#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
	int h, w, rs, cs, rt, ct;
	cin >> h >> w >> rs >> cs >> rt >> ct;
	vector<vector<char>> hw(h, vector<char>(w));
	REP(i, h)
	{
		REP(j, w) { cin >> hw[i][j]; }
	}
	return (0);
}
