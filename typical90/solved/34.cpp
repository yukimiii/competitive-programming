#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, k;
	int ans = 0;
	int kind = 0;
	cin >> n >> k;
	map<ll, ll> cnt;
	vector<ll> a(n);
	REP(i, n) { cin >> a[i]; }
	int l = 0;
	int r = 0;
	while (r < n)
	{
		if (cnt[a[r]] == 0 && kind == k)
			break;
		else if (cnt[a[r]] == 0)
		{
			kind++;
		}
		cnt[a[r]]++;
		r++;
	}
	ans = r - l;
	// cout << ans << endl;
	while (r < n)
	{
		while (cnt[a[l]] != 1)
		{
			cnt[a[l]]--;
			l++;
		}
		cnt[a[l]]--;
		l++;
		int flag = 0;
		while (flag == 0 || cnt[a[r]] != 0)
		{
			if (cnt[a[r]] == 0)
				flag = 1;
			cnt[a[r]]++;
			r++;
			if (r >= n)
			{
				break;
			}
		}
		// cout << l << " " << r << endl;
		ans = max(ans, r - l);
	}
	cout << ans << endl;
	return (0);
}
