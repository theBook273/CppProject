#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int left = 0, right = 0;
    int ans = 0;

    vector<int> mp(256, -1);

    while (right < s.size())
    {
        if (mp[s[right]] != -1)
        {
            left = max(left, mp[s[right]] + 1);
            // cout << left << " " << mp[s[right]] << "\n";
        }

        cout << right << " \n";
        mp[s[right]] = right;

        ans = max(ans, right - left + 1);

        right++;
    }

    cout << ans;
}