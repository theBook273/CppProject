#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    pair<int, int> sizeOfRectangle;
    int ans = 0;

public:
    solution()
    {
        freopen("SHAPE.INP", "r", stdin);
        freopen("SHAPE.OUT", "w", stdout);

        int length, width;

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

    int solve()
    {
        while (sizeOfRectangle.first % sizeOfRectangle.second != 0)
        {
            ans += int(sizeOfRectangle.first / sizeOfRectangle.second);

            sizeOfRectangle.first -= (sizeOfRectangle.second * int(sizeOfRectangle.first / sizeOfRectangle.second));

            checkToSwapLenghtAndWidth();
        }

        return ans + int(sizeOfRectangle.first / sizeOfRectangle.second);
    }
};

int main()
{
    solution a;
    cout << a.solve() << endl;
}