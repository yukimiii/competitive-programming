#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main() {
	int n = 20;
	ll cnt = 4;
	ll ans = 0;
	vector<vector<ll>> vv(n, vector<ll>(n));
	REP(i, n) {
		REP(j, n) { cin >> vv[i][j]; }
	}
	ll tmp = 1;
	REP(i, n - cnt) {
		REP(j, n - cnt) {
			tmp = 1;
			REP(k, cnt) { tmp *= vv[i + k][j + k]; }
			ans = max(ans, tmp);
		}
	}
	REP(i, n - cnt + 1) {
		REP(j, n - cnt) {
			tmp = 1;
			REP(k, cnt) { tmp *= vv[n - i - k - 1][j + k]; }
			cout << n - i - 1 << " " << j << " " << tmp << endl;
			ans = max(ans, tmp);
		}
	}
	REP(i, n) {
		REP(j, n - cnt) {
			tmp = 1;
			REP(k, cnt) { tmp *= vv[i][j + k]; }
			// cout << i << " " << j << " " << tmp << endl;
			ans = max(ans, tmp);
		}
	}
	REP(j, n) {
		REP(i, n - cnt) {
			tmp = 1;
			REP(k, cnt) { tmp *= vv[i + k][j]; }
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return (0);
}
