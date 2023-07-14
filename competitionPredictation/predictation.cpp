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

    pair<ll, ll> createPointAndPenalty()
    {
        pair<ll, ll> pointAndPenalty = {0, 0};

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
            pointAndPenalty.second += tempTime;
            sortedTime.pop();
        }

        pointAndPenalty.first = (numberOfTasks - sortedTime.size());
        pointAndPenalty.second = 0 - pointAndPenalty.second;

        return pointAndPenalty;
    }

    ll solve()
    {
        for (ll i = 0; i < participants; i++)
        {

            pair<ll, ll> point = createPointAndPenalty();

            if (i == 0)
            {
                rudolf = point;
            }
            else
            {
                if (rudolf < point)
                {
                    ans++;
                }
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

    ll t;

    cin >> t;

    while (t--)
    {
        solution obj;
        cout << obj.solve() << "\n";
    }
}