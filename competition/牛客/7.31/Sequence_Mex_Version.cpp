#include<bits/stdc++.h>
using namespace std;

void print (const vector<int> &a) { for (auto &x : a) cout << x << ' ';}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> b(n), c(n);
    auto mex = [&](int x, int y, int z) -> int {
        bool has[4] = {};
        if (x < 3) has[x] = 1;
        if (y < 3) has[y] = 1;
        if (z < 3) has[z] = 1;
        int p = 0;
        while (has[p]) p++;
        return p;
    };
    for (int i = 0; i < n; i++) b[i] = mex(a[i], a[(i + 1) % n], a[(i - 1 + n) % n]);
    for (int i = 0; i < n; i++) c[i] = mex(b[i], b[(i + 1) % n], b[(i - 1 + n) % n]);
    if (k == 1) {
        print(b);
        return;
    }
    if (k == 2) {
        print(c);
        return;
	}
    for (int t = 3; t <= k; t++) {
        vector <int> tmp(n);
        tmp = c;
        for (int i = 0; i < n; i++) c[i] = mex(tmp[i], tmp[(i + 1) % n], tmp[(i - 1 + n) % n]);
        a = b;
        b = tmp;
        if (a == c) {
            if ((k - t) & 1) print(b);
            else print(a);
            return;
        }
    }
    print(c);
}   

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}