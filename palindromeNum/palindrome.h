#include <bits/stdc++.h>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string temp = std::to_string(x);

        int i = 0, j = temp.size() - 1;

        while (i <= j)
        {
            if (temp[i] != temp[j])
            {
                return 0;
            }
            i++;
            j--;
        }

        return 1;
    }
};