#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    vector<pair<long long, long long>> mlAndSpace;

    int n, tong = 0;

public:
    solution()
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            mlAndSpace.push_back({temp1, temp2});
        }
    }

    void passAnilin()
    {
        long long right = 0, i = 1;

        sort(mlAndSpace.rbegin(), mlAndSpace.rend());

        while (right < i && i < mlAndSpace.size())
        {

            if (mlAndSpace[right].first + mlAndSpace[i].first <= mlAndSpace[right].second)
            {
                mlAndSpace[right].first += mlAndSpace[i].first;
                mlAndSpace[i].first = 0;
            }
            else
            {
                mlAndSpace[i].first = mlAndSpace[i].first + mlAndSpace[right].first - mlAndSpace[right].second;
                mlAndSpace[right].first = mlAndSpace[right].second;
            }

            if (mlAndSpace[right].second == mlAndSpace[right].first)
            {
                right++;
            }

            i++;
        }

        sort(mlAndSpace.rbegin(), mlAndSpace.rend());

        for (int i = mlAndSpace.size() - 1; i >= 0; i--)
        {
            if (mlAndSpace[i].first == 0)
            {
                tong++;
            }
            else
            {
                break;
            }
        }
    }

    void printAnilin()
    {
        passAnilin();

        cout << tong << endl;

        for (int i = 0; i < mlAndSpace.size(); i++)
        {
            cout << mlAndSpace[i].first << " ";
        }
    }
};

int main()
{
    solution a;

    a.printAnilin();
}