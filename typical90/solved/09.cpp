#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

double getangle(double a1, double a2)
{
	double ret = abs(a1 - a2);
	if (ret >= 180)
		ret = 360.0 - ret;
	return ret;
}

int main()
{
	int n;
	double ans = 0;
	cin >> n;
	vector<double> a(n), b(n);
	REP(i, n) { cin >> a[i] >> b[i]; }
	REP(j, n)
	{
		vector<double> arg;
		REP(i, n)
		{
			if (i == j)
				continue;
			arg.push_back(atan2(b[i] - b[j], a[i] - a[j]) * 180.0 / 3.14159265358979);
		}
		sort(arg.begin(), arg.end());

		REP(i, n - 1)
		{
			double target = arg[i] + 180.0;
			if (target >= 360.0)
				target -= 360.0;
			int pos1 = lower_bound(arg.begin(), arg.end(), target) - arg.begin();
			int CandIdx1 = pos1 % (n - 1);
			int CandIdx2 = (pos1 + n - 2) % (n - 1);
			double Candidate1 = getangle(arg[i], arg[CandIdx1]);
			double Candidate2 = getangle(arg[i], arg[CandIdx2]);
			ans = max({ans, Candidate1, Candidate2});
		}
	}
	std::cout << std::setprecision(8);

	cout << ans << endl;
	return (0);
}
