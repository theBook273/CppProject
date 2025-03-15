#include <bits/stdc++.h>

using namespace std;

vector<int> buoc[100000];
pair<int, int> moveSet[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void move(int x, int y, int tong, vector<char> a[])
{
    queue<pair<int, int>> q;

    q.push({x, y});

    a[x][y] = '*';

    while (!q.empty())
    {
        pair<int, int> pos = q.front();

        q.pop();

        if (pos.first == pos.second && pos.second == 1)
        {
            cout << buoc[pos.first][pos.second] << endl;
            return;
        }

        for (auto i : moveSet)
        {
            if (a[pos.first + i.first][pos.second + i.second] == '.')
            {
                buoc[pos.first + i.first][pos.second + i.second] = buoc[pos.first][pos.second] + 1;
                q.push({pos.first + i.first, pos.second + i.second});
                a[pos.first + i.first][pos.second + i.second] = '*';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, x, y;

    cin >> n >> m;

    vector<char> a[100000];

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            a[i].push_back('*');
            buoc[i].push_back(0);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'B')
            {
                a[i][j] = '.';
            }
            if (a[i][j] == 'C')
            {
                x = i;
                y = j;
            }
        }
    }

    move(x, y, 0, a);
}
