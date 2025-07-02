#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string a, b;

    string mark;

    cin >> a >> mark >> b;

    long long maxofsize = max(a.size() + 1, b.size() + 2);

    string disA = "#", disB = mark + "#";

    while (disA.size() + a.size() < maxofsize)
    {
        disA += "#";
    }

    while (disB.size() + b.size() < maxofsize)
    {
        disB += "#";
    }

    disA += a;
    disB += b;
    cout << disA << endl;
    cout << disB << endl;

    for (long long i = 0; i < maxofsize; i++)
    {
        cout << "-";
    }
    cout << endl;

    stack<long long> res;
    long long nho = 0;

    if (mark == "+")
    {
        for (long long i = disA.size() - 1; i >= 0; i--)
        {
            if (disA[i] != '#' && disB[i] != '#' && disB[i] != '+')
            {
                if ((disA[i] - '0') + (disB[i] - '0') + nho <= 9)
                {
                    res.push((disA[i] - '0') + (disB[i] - '0') + nho);
                    nho = 0;
                }
                else
                {
                    res.push(to_string((disA[i] - '0') + (disB[i] - '0') + nho)[1] - '0');
                    nho = to_string((disA[i] - '0') + (disB[i] - '0') + nho)[0] - '0';
                }
            }

            else if (disA[i] != '#')
            {
                res.push(disA[i] - '0' + nho);
                nho = 0;
            }
            else if (disB[i] != '#' && disB[i] != '+')
            {
                res.push(disB[i] - '0' + nho);
                nho = 0;
            }
            else if (nho != 0)
            {
                res.push(nho);
                nho = 0;
            }
        }
    }

    if (mark == "-")
    {
        for (long long i = disA.size() - 1; i >= 0; i--)
        {
            if (disA[i] != '#' && disB[i] != '#' && disB[i] != '+')
            {
                if ((disA[i] - '0') - (disB[i] - '0') - nho >= 0)
                {
                    res.push((disA[i] - '0') - (disB[i] - '0') - nho);
                    nho = 0;
                }
                else
                {
                    res.push(10 + (disA[i] - '0') - (disB[i] - '0') - nho);
                    nho = 1;
                }
            }

            else if (disA[i] != '#')
            {
                res.push(disA[i] - '0' - nho);
                nho = 0;
            }
            else if (disB[i] != '#' && disB[i] != '-')
            {
                res.push(disB[i] - '0' - nho);
                nho = 0;
            }
        }
    }

    while (res.top() == 0)
    {
        res.pop();
    }

    long long temp = 0;

    while (temp + res.size() < maxofsize)
    {
        cout << "#";
        temp++;
    }

    while (!res.empty())
    {
        cout << res.top();
        res.pop();
    }
}
