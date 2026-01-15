#include<bits/stdc++.h>
#define double long double

using namespace std;

struct Point{
    double x, y;
};

int n;
vector<Point> point;

double S(vector<Point> &a){
    double res = 0;
    for(int i = 0; i < n; i++){
        int now = i;
        int next = (i + 1) % n;
        res += (a[now].x + a[next].x) * (a[now].y - a[next].y);
    }
    res /= 2;
    res = abs(res);
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    point.resize(n);
    for(Point &i : point){
        cin >> i.x >> i.y;
    }

    cout << fixed << setprecision(9) << S(point);
}
