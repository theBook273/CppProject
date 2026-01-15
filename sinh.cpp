#include<bits/stdc++.h>
#define int long long

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l,r) (rng);
}

const int N = 1e5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream inp("test.inp");

    for(int i = 1; i < N; i++){
        inp << rnd(1,N) << "\n";
    }

    inp.close();

    cout << "DONE TEST\n";
}
