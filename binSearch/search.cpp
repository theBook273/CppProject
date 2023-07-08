#include <bits/stdc++.h>

using namespace std;

int n, m, vector<vector<int>> matrix, target;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp1, temp2;
            cin >> temp1, temp2;
            matrix[temp1].push_back(temp1);
            matrix[temp2].push_back(temp2);
        }
    }

    cin >> target;

    int n = matrix[0].size();
    int m = matrix.size();

    for (int i = 0; i < n; i++)
    {
        int r = m - 1, l = 0;

        while (l <= r)
        {
            int mid = (r + l) / 2;

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