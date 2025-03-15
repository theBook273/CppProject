#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    if (b == 0) {
        cout << "NONE" << endl;
    } else
        cout << a << " div " << b << " = " << a / b;
}