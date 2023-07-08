#include <bits/stdc++.h>

using namespace std;

int main()
{
    string t, s;

    cin >> t >> s;

    if (t.size() != s.size())
    {
        return 0;
    }

    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for (int i = 0; i <= 25; i++)
    {
        if (arr[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}