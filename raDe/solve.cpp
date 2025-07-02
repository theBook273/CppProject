#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long a, b, c, n;

    cin >> a >> b >> c >> n;

    // if (a * b * c > 0 && a + b + c >= n && n >= 3)
    //     cout << "YES";
    // else
    //     cout << "NO";

    cout << ((a * b * c > 0 && a + b + c >= n && n >= 3) ? "YES" : "NO") << endl;
}
