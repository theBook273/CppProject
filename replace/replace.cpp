#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    string s;

    cin >> s >> n;

    unordered_map<char, int> mp;

    int left = 0, replacement = 0, res = 0;

    for (int right = 0; right < s.size(); right++)
    {
        mp[s[right]]++;

        replacement = max(replacement, mp[s[right]]);

        if (right - left + 1 - replacement > n)
        {
            mp[s[left]]--;
            left++;
        }

        res = max(res, right - left + 1);
    }
}