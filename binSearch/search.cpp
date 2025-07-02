#include <bits/stdc++.h>

using namespace std;

long long n, m, vector<vector<long long>> matrix, target;

long long main()
{
    cin >> n >> m;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            long long temp1, temp2;
            cin >> temp1, temp2;
            matrix[temp1].push_back(temp1);
            matrix[temp2].push_back(temp2);
        }
    }

    cin >> target;

    long long n = matrix[0].size();
    long long m = matrix.size();

    for (long long i = 0; i < n; i++)
    {
        long long r = m - 1, l = 0;

        while (l <= r)
        {
            long long mid = (r + l) / 2;

            if (matrix[i][mid] == target)
            {
                cout << 1;
            }
            else if (matrix[i][mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
    }

    cout << 0;
}
