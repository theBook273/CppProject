#include <bits/stdc++.h>
#define int long long

using namespace std;

int k, n, m;
vector<int> a, b, aNev, bNev, aZe, bZe, aPos, bPos;

void splitA(vector<int> &a, vector<int> &Nev, vector<int> &Ze, vector<int> &Pos) {
    for(auto i : a) {
        if(i < 0) {
            Nev.push_back(i);
        } else if(i == 0) {
            Ze.push_back(i);
        } else {
            Pos.push_back(i);
        }
    }
}

int check(long long x) {
    long long dem = 0;

    if (x >= 0) {
        dem += aZe.size() * b.size();
        dem += bZe.size() * a.size();
    }


    if (x >= 0) dem += aNev.size() * bPos.size();
    else {
        for (long long i : aNev) {
            long double need = (long double)x / i;
            dem += bPos.end() - upper_bound(bPos.begin(), bPos.end(), need);
        }
    }


    if (x >= 0) dem += aPos.size() * bNev.size();
    else {
        for (long long i : aPos) {
            long double need = (long double)x / i;
            dem += lower_bound(bNev.begin(), bNev.end(), need) - bNev.begin();
        }
    }

    for (long long i : aPos) {
        long double need = (long double)x / i;
        dem += upper_bound(bPos.begin(), bPos.end(), need) - bPos.begin();
    }

    for (long long i : aNev) {
        long double need = (long double)x / i;
        dem += bNev.end() - lower_bound(bNev.begin(), bNev.end(), need);
    }

    return dem;
}

signed main() {
    cin.tie()->sync_with_stdio(0);

//    freopen("MEGARR_input0.txt", "r", stdin);
//    freopen("MEGARR_output0.txt", "w", stdout);

    cin >> k;

    cin >> n;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
    }

    cin >> m;
    b.resize(m);
    for (auto &i : b) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    splitA(a,aNev,aZe,aPos);
    splitA(b,bNev,bZe,bPos);

    int l = -4e18, r= 4e18, ans = 0;
    while(l <= r) {
        int mid((l + r) / 2);
        int cnt = check(mid);

        if(cnt >= k) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;
}
