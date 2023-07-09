#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    priority_queue<int, vector<int>, greater<int>> pr;
    int n, k;

public:
    solution()
    {
        freopen("CIRCLE.INP", "r", stdin);
        freopen("CIRCLE.OUT", "w", stdout);

        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            pr.push(temp);
        }
    }

    int res()
    {
        while (!pr.empty() && pr.top() <= k)
        {
            k += pr.top();
            pr.pop();
        }
        return k;
    }
};

int main()
{
    solution a;
    cout << a.res() << endl;
    return 0;
}