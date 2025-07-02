#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    priority_queue<long long, vector<long long>, greater<long long>> pr;
    long long n, k;

public:
    solution()
    {
        freopen("CIRCLE.INP", "r", stdin);
        freopen("CIRCLE.OUT", "w", stdout);

        cin >> n >> k;

        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            pr.push(temp);
        }
    }

    long long res()
    {
        while (!pr.empty() && pr.top() <= k)
        {
            k += pr.top();
            pr.pop();
        }
        return k;
    }
};

long long main()
{
    solution a;
    cout << a.res() << endl;
    return 0;
}
