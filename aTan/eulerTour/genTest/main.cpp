#include<bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l,r) (rng);
}

const int limT = 55;
const int limE = 2e5;
const int limQ = 1e6;
const int limX = 1e9;

signed main(){
    srand(time(nullptr));

    ofstream inp("euler.inp");

    for(int test = 1; test <= limT; test++){
        int n = rnd(1, limE);

        inp << n << "\n";
        for(int i = 2; i <= n; i++){
            int p = rnd(1, i - 1);
            inp << i << " " << p << "\n";
        }

        int q = rnd(1, limQ);
        inp << q << "\n";
        while(q--){
            int type = rnd(1,2);
            if(type == 1){
                inp << type << " " << rnd(1, n) << " " << rnd(-limX, limX) << "\n";
            }
            else {
                inp << type << " " << rnd(1, n) << "\n";
            }
        }
        inp.close();
        //===========================END GEN===========================

        //===========================CHECKER===========================
        cout << "RUNNING ON TEST " << test << ": ";

        system("./trau");
        system("./chuan");

        int check = system("diff euler.out euler.ans");

        if(check){
            cout << "WA\n\n";
            return 0;
        }
        cout << "AC\n";
    }
}
