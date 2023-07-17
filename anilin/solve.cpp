#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    vector<pair<long long, long long>> spaceAndMl;

    long long n, tong = 0;

public:
    solution()
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            spaceAndMl.push_back({temp2, temp1});
        }
    }

    void passAnilin()
    {
        long long right = 0, i = 1;

        sort(spaceAndMl.rbegin(), spaceAndMl.rend());

        while (right < i && i < spaceAndMl.size())
        {

            if (spaceAndMl[right].second + spaceAndMl[i].second <= spaceAndMl[right].first)
            {
                spaceAndMl[right].second += spaceAndMl[i].second;
                spaceAndMl[i].second = 0;
            }
            else
            {
                spaceAndMl[i].second = spaceAndMl[i].second + spaceAndMl[right].second - spaceAndMl[right].first;
                spaceAndMl[right].second = spaceAndMl[right].first;
            }

            if (spaceAndMl[right].second == spaceAndMl[right].first)
            {
                right++;
            }

            i++;
        }

        for (int i = spaceAndMl.size() - 1; i >= 0; i--)
        {
            if (spaceAndMl[i].second == 0)
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

        for (int i = 0; i < spaceAndMl.size(); i++)
        {
            cout << spaceAndMl[i].second << " ";
        }
    }
};

int main()
{
    solution a;

    a.printAnilin();
}