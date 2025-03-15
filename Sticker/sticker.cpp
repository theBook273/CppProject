#include<bits/stdc++.h>

using namespace std;

int number[15], targetNum[15], res[100];
string inNum, target;
int  finall = 1e9;

int main()
{
    cin >> inNum >> target;

    for(char i : inNum)
    {
        number[i - '0']++;
    }

    for(char i : target)
    {
        targetNum[i - '0']++;
    }

    for(int i = 0; i <= 10; i++)
    {
        if(targetNum[i] != 0)
        {
            if(i == 5 || i == 2)
            {
                res[i] = (number[5] + number[2]) / targetNum[i];
                continue;
            }

            if(i == 9 || i == 6)
            {
                res[i] = (number[9] + number[6]) / targetNum[i];
                continue;
            }

            res[i] = number[i] / targetNum[i];
        }
    }

    for(int i = 0; i <= 10; i++)
    {
        if(res[i] != 0 && res[i] < finall)
        {
            finall = res[i];
        }
    }

    if(finall != 1e9)
    {
        cout << finall;
        return 0;
    }

    cout << 0;
}
