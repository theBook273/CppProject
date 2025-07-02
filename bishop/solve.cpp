#include <bits/stdc++.h>

using namespace std;

vector<char> board[100000];

pair<long long, long long> moveSet[] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<long long> step[100000];

long long main()
{
    long long n, m, p, q, s, t;

    cin >> n >> m >> p >> q >> s >> t;

    for (long long i = 0; i <= n + 1; i++)
    {
        for (long long j = 0; j <= n + 1; j++)
        {
            board[i].push_back('*');
            step[i].push_back(0);
        }
    }

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            board[i][j] = '.';
        }
    }

    pair<long long, long long> target = {s, t};

    for (long long i = 0; i < m; i++)
    {
        long long temp1, temp2;

        cin >> temp1 >> temp2;

        board[temp1][temp2] = '*';
    }

    queue<pair<long long, long long>> nextMove;

    nextMove.push({p, q});

    board[p][q] = '*';

    // cout << endl;

    while (!nextMove.empty())
    {
        pair<long long, long long> current = nextMove.front();
        nextMove.pop();

        if (current == target)
        {
            cout << step[current.first][current.second] << endl;
            return 0;
        }

        for (auto i : moveSet)
        {
            pair<long long, long long> temp = current;
            while (board[temp.first + i.first][temp.second + i.second] == '.')
            {
                temp.first += i.first;
                temp.second += i.second;
                board[temp.first][temp.second] = '*';
                step[temp.first][temp.second] = step[current.first][current.second] + 1;
                // cout << temp.first << " " << temp.second << " " << step[temp.first][temp.second] << endl;
                nextMove.push({temp.first, temp.second});
            }
            // cout << endl;
        }
    }

    cout << -1;
}
