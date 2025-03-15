#include <bits/stdc++.h>

using namespace std;

string s[100000];

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    unordered_map<string, vector<string>> mapS;
    set<string> a;

    for (int i = 0; i < n; i++)
    {
        string temp = s[i];
        sort(temp.begin(), temp.end());

        a.insert(temp);

        mapS[temp].push_back(s[i]);
    }

    vector<vector<string>> res;

    for (string i : a)
    {
        res.push_back(mapS[i]);
    }

    return res;
}