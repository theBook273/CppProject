#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    long long n, k;
    string s;

public:
    solution()
    {
        cin >> n >> k >> s;
    }

    long long securityNum()
    {
        int security = 0, highest = 0;

        for (long long i = 0; i < n; i++)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                security += (s[i] - 'a' + 1);
                highest = max(highest, s[i] - 'a' + 1);
            }
            else if ('A' <= s[i] && s[i] <= 'Z')
            {
                security += ((s[i] - 'A' + 1) * 2);
                highest = max(highest, ((s[i] - 'A' + 1) * 2));
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                security += (s[i] - '0');
                highest = max(highest, s[i] - '0');
            }
            else
            {
                security += (highest);
            }
        }

        return security;
    }

    bool check()
    {
        return securityNum() >= k;
    }
};

int main()
{
    solution a;

    string res = "BAO MAT";

    cout << a.securityNum() << endl;

    if (!a.check())
    {
        res = "KHONG " + res;
    }

    cout << res << endl;
}