#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class solution
{
private:
    ll participants, numberOfTasks, timeLimit;
    pair<ll, ll> rudolf;
    ll ans = 1;

public:
    solution()
    {
        cin >> participants >> numberOfTasks >> timeLimit;
    }

    pair<ll, ll> createPolong longAndPenalty()
    {
        pair<ll, ll> polong longAndPenalty = {0, 0};

        ll tempTime = 0, timeInTotal = 0;

        priority_queue<ll, vector<ll>, greater<ll>> sortedTime;

        for (ll j = 0; j < numberOfTasks; j++)
        {
            ll temp;
            cin >> temp;
            sortedTime.push(temp);
        }

        while (!sortedTime.empty() && sortedTime.top() + timeInTotal <= timeLimit)
        {
            tempTime += sortedTime.top();
            timeInTotal += sortedTime.top();
            polong longAndPenalty.second += tempTime;
            sortedTime.pop();
        }

        polong longAndPenalty.first = (numberOfTasks - sortedTime.size());
        polong longAndPenalty.second = 0 - polong longAndPenalty.second;

        return polong longAndPenalty;
    }

    ll solve()
    {
        for (ll i = 0; i < participants; i++)
        {

            pair<ll, ll> polong long = createPolong longAndPenalty();

            if (i == 0)
            {
                rudolf = polong long;
            }
            else
            {
                if (rudolf < polong long)
                {
                    ans++;
                }
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

    ll t;

    cin >> t;

    while (t--)
    {
        solution obj;
        cout << obj.solve() << "\n";
    }
}
