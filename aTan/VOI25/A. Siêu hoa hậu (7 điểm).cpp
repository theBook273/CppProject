#include<bits/stdc++.h>
#define int long long

using namespace std;

struct Person{
    int w,x,y,z;
    const bool operator<(const Person&other){
        return w < other.w;
    }
};

int n, res = 0;
vector<Person> a;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TESTRANDOM.INP", "r", stdin);
    freopen("TESTRANDOM.OUT", "w", stdout);

    cin >> n;
    a.resize(n);
    for(Person &p : a){
        cin >> p.w >> p.x >> p.y >> p.z;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i].x < a[j].x && a[i].y < a[j].y && a[i].w < a[j].w && a[i].z < a[j].z){
                res++;
                break;
            }
        }
    }

    cout << res;
}


