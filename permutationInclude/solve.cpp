#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    unordered_map<char, int> mp1, mp2;

    if (s1.size() > s2.size())
    {
        return 0;
    }

    for (auto i : s1)
    {
        mp1[i]++;
    }

    int left = 0;

    for (int right = 0; right < s1.size(); right++)
    {
        mp2[s2[right]]++;

        if (right - left + 1 == s1.size())
        {
            while (left < right)
            {
                if (mp1.count(s2[left]) == 0)
                {
                    return 0;
                }
                left++;
            }
            return 1;
        }
    }

    return 0;
}