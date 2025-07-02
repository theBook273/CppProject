#include <bits/stdc++.h>

using namespace std;

long long main()
{
    double x, y, z;

    cin >> x >> y >> z;

    cout << fixed << setprecision(0) << 4 * (sqrt((x * y) / z) + sqrt((z * y) / x) + sqrt((z * x) / y));
}
