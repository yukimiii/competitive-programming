#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int lines;

    cin >> lines;
    vector<vector<int>> pyramid(lines, vector<int>(lines));

    string name = "067_triangle.txt";
    // C++のファイル入力のための準備ifsに読み込まれた
    std::ifstream ifs(name, ios::in);
    // ファイルを開くのに失敗したときの処理一応書く
    if (!ifs)
    {
        return 1;
    }

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            ifs >> pyramid.at(i).at(j);
        }
    }
    while (lines > 1)
    {
        for (int i = 0; i < lines; i++)
        {
            pyramid[lines - 2][i] += max(pyramid[lines - 1][i], pyramid[lines - 1][i + 1]);
        }
        lines--;
    }
    cout << pyramid[0][0] << "\n";
    return (0);
}
