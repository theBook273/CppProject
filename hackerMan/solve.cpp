#include <bits/stdc++.h>

using namespace std;

pair<int, int> moveSet[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {0, 0}};
// U D L R
int x, y, n;
pair<int, int> posOfB = {0, 0};

bool check()
{
    for (auto i : moveSet)
    {
        if (x + i.first == posOfB.first && y + i.second == posOfB.second)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> x >> y;

    cin >> n;

    string s;

    cin >> s;

    bool listened = 0;

    if (check())
    {
        cout << 0 << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        switch (s[i - 1])
        {
        case 'U':
            posOfB.first += moveSet[0].first;
            posOfB.second += moveSet[0].second;

            break;

        case 'D':
            posOfB.first += moveSet[1].first;
            posOfB.second += moveSet[1].second;
            break;

        case 'L':
            posOfB.first += moveSet[2].first;
            posOfB.second += moveSet[2].second;
            break;

        case 'R':
            posOfB.first += moveSet[3].first;
            posOfB.second += moveSet[3].second;
            break;

        default:
            break;
        }
        if (check())
        {
            listened = 1;
            cout << i << endl;
        }
    }

    if (!listened)
    {
        cout << -1;
    }
}