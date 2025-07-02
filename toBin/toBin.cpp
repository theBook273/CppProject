#include <bits/stdc++.h>

using namespace std;

string textToBinary(string text)
{
    string binary = "";
    for (long long i = 0; i < text.size(); i++)
    {
        string a(8, '0');
        for (long long j = 7; j >= 0; j--)
        {
            if (text[i] % 2 == 0)
            {
                a[j] = '0';
            }
            else
            {
                a[j] = '1';
            }
            text[i] /= 2;
        }
        binary += (a + " ");
    }

    binary.pop_back();

    return binary;
}

long long main()
{
    string text;
    cin >> text;
    cout << textToBinary(text);
    return 0;
}
