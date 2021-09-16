#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	ll a, b, ans;
	cin >> a >> b;
	ans = lcm(a, b);
	// a*b/gcd(a,b)だとオーバーフローする
	if (b / gcd(a, b) > 1000000000000000000 / a)
		cout << "Large" << endl;
	else
		cout << ans << endl;
	return (0);
}
