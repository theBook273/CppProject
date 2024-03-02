#include <iostream>

using namespace std;

int main() {
    string a = "hello";

    a[0] = toupper(a[0]);

    cout << a;
}