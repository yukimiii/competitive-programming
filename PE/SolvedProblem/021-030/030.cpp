#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int limit = 6 * 9 * 9 * 9 * 9 * 9;
long long power(int base, int power)
{
	long long num = 1;
	while (power > 0)
	{
		num *= base;
		power--;
	}
	return (num);
}

int main()
{
	vector<int> powerfive(10);
	int sum;
	int chknum;
	sum = 0;

	for (int i = 0; i < 10; i++)
	{
		powerfive[i] = power(i, 5);
	}
	for (int i = 2; i <= limit; i++)
	{
		chknum = 0;
		int keepnum;
		keepnum = i;

		while (keepnum > 0)
		{
			chknum += powerfive[keepnum % 10];
			if (chknum == i && keepnum / 10 == 0)
			{
				//	cout << i << endl;
				sum += i;
			}
			keepnum /= 10;
		}
	}
	cout << sum << "\n";
	return (0);
}
