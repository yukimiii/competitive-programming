#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int c = N / 2; c >= N / 3; c--)
    {
        for (int a = 1; a <= N / 4; a++)
        {
            if (a * a + (N - a - c) * (N - a - c) == c * c)
            {
                cout << a * (N - a - c) * c << "\n";
                return (0);
            }
        }
    }
    cout << "no answer\n";
    return (0);
}
