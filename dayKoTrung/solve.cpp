#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string s;

    cin >> s;

    unordered_map<char, long long> mp;

    long long left = 0, maxLeght = 0;

    for (long long right = 0; right < s.size(); right++)
    {
        mp[s[right]]++;

        if (mp.size() == right - left + 1)
        {
            maxLeght = max(maxLeght, right - left + 1);
        }

        else if (mp.size() < right - left + 1)
        {
            while (mp.size() < right - left + 1)
            {
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }
        }
    }

    return maxLeght;
}
