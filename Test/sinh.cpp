#include<bits/stdc++.h>
#define int long long

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rd(int l, int r) {
    return uniform_int_distribution<int>(l,r) (rng);
}

signed main(){
    srand(time(nullptr));
}
