#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//改行判定するのも数えるのも面倒だったからツールで改行消したものを入力したのがいまいち
vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
	{
		if (!item.empty())
		{
			elems.push_back(item);
		}
	}
	return elems;
}

int main()
{
	string nums;
	cin >> nums;
	ll adjant13;
	ll adjantmax = 0;
	int i = 0;
	vector<string> splitnums = split(nums, '0');
	splitnums.push_back("end");
	// cout << splitnums[0] << "\n";
	while (splitnums[i] != "end")
	{
		int length = splitnums[i].size();
		if (length > 12)
		{
			for (int start = 0; start < length - 12; start++)
			{
				adjant13 = 1;
				for (int k = start; k < start + 13; k++)
				{
					adjant13 *= splitnums[i][k] - '0';
					// cout << splitnums[i][k] - '0';
				}
				adjantmax = max(adjant13, adjantmax);
			}
		}
		i++;
	}
	cout << adjantmax << "\n";
	return (0);
}
