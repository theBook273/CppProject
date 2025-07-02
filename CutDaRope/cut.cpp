#include <bits/stdc++.h>

using namespace std;

class cutDaRope
{
private:
    vector<long long> highOfNails;
    vector<long long> lengthOfStrings;
    long long numberOfNails;

public:
    cutDaRope()
    {
        cin >> numberOfNails;

        for (long long i = 0; i < numberOfNails; i++)
        {
            long long temp;

            cin >> temp;
            highOfNails.push_back(temp);

            cin >> temp;
            lengthOfStrings.push_back(temp);
        }
    }

    long long solve()
    {
        long long ans = 0;

        for (long long i = 0; i < numberOfNails; i++)
        {
            if (lengthOfStrings[i] < highOfNails[i])
            {
                ans++;
            }
        }

        return ans;
    }
};

long long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {
        cutDaRope a;
        cout << a.solve() << "\n";
    }
}
