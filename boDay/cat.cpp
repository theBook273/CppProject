#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, tong = 0;

    cin >> n;

    string s;

    cin >> s;

    int left = 0;

    unordered_map<char, vector<int>> vaoDau, raCuoi;

    for (int i = 0; i < n; i++)
    {
        vaoDau[s[i]].push_back(i);
    }

    if (vaoDau.size() < 6)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (vaoDau[s[i]].size() > 1)
        {
            raCuoi[s[i]].push_back(i);
            vaoDau[s[i]].pop_back();
            tong++;
            continue;
        }

        break;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (vaoDau[s[i]].size() > 1)
        {
            raCuoi[s[i]].push_back(i);
            vaoDau[s[i]].pop_back();
            tong++;
            continue;
        }
        break;
    }

    for (int i = 0; i < n; i++)
    {
        if (raCuoi[s[i]].size() >= 1)
        {
            tong++;
            raCuoi[s[i]].pop_back();
            continue;
        }
    }

    cout << tong + 1;
}