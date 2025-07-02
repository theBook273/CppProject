#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    pair<long long, long long> sizeOfRectangle;
    long long ans = 0;

public:
    solution()
    {
        freopen("SHAPE.INP", "r", stdin);
        freopen("SHAPE.OUT", "w", stdout);

        long long length, width;

        cin >> length >> width;

        sizeOfRectangle = {length, width};
    }

    void checkToSwapLenghtAndWidth()
    {
        if (sizeOfRectangle.first < sizeOfRectangle.second)
        {
            swap(sizeOfRectangle.first, sizeOfRectangle.second);
        }
    }

    long long solve()
    {
        while (sizeOfRectangle.first % sizeOfRectangle.second != 0)
        {
            ans += long long(sizeOfRectangle.first / sizeOfRectangle.second);

            sizeOfRectangle.first -= (sizeOfRectangle.second * long long(sizeOfRectangle.first / sizeOfRectangle.second));

            checkToSwapLenghtAndWidth();
        }

        return ans + long long(sizeOfRectangle.first / sizeOfRectangle.second);
    }
};

long long main()
{
    solution a;
    cout << a.solve() << endl;
}
