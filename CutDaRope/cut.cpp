#include <bits/stdc++.h>

using namespace std;

class cutDaRope
{
private:
    vector<int> highOfNails;
    vector<int> lengthOfStrings;
    int numberOfNails;

public:
    cutDaRope()
    {
        cin >> numberOfNails;

        for (int i = 0; i < numberOfNails; i++)
        {
            int temp;

            cin >> temp;
            highOfNails.push_back(temp);

            cin >> temp;
            lengthOfStrings.push_back(temp);
        }
    }

    int solve()
    {
        int ans = 0;

        for (int i = 0; i < numberOfNails; i++)
        {
            if (lengthOfStrings[i] < highOfNails[i])
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cutDaRope a;
        cout << a.solve() << "\n";
    }
}