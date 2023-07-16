#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    long long n;
    vector<long long> container;
    map<long long, long long, greater<long long>> appear;

public:
    solution()
    {
        cin >> n;

        for (long long i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            container.push_back(temp);
            appear[temp]++;
        }

        for (auto i : appear)
        {
            if (appear.count(i.first + 1))
            {
                i.second += appear[i.first + 1];
            }

            if (appear.count(i.first - 1))
            {
                i.second += appear[i.first - 1];
            }
            cout << i.first << " " << i.second << endl;
        }
    }

    int res
    {
        for (auto i : appear)
        {
        }
    }
};

int main()
{
    solution a;
}