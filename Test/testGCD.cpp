#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;

        long long tong3 = (3 + ((n - 1 / 3) * 3)) * ((((n - 1 / 3) * 3) - 3) / 3 + 1) / 2;
        long long tong5 = (5 + ((n - 1 / 5) * 5)) * ((((n - 1 / 5) * 5) - 5) / 5 + 1) / 2;
        long long tong15 = (15 + ((n - 1 / 15) * 15)) * ((((n - 1 / 15) * 15) - 15) / 15 + 1) / 2;

        cout << tong3 + tong5;
    }

    return 0;
}