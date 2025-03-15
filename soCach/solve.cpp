#include <bits/stdc++.h>

using namespace std;

int n, k;

string nums = "0";

vector<string> res;

void solve(int dem)
{
    for (int i = nums[dem - 1] - '0' + 1; i <= n; i++)
    {
        nums += to_string(i);
        if (dem == k)
        {
            res.push_back(nums);
        }
        else
            solve(dem + 1);
        nums.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);

    cin >> n >> k;

    solve(1);

    cout << res.size() << endl;

    for (auto i : res)
    {
        for (int j = 1; j < i.size(); j++)
        {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}