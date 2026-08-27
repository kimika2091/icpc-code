#include<bits/stdc++.h>
using namespace std;

int check(int x) {
    return __builtin_popcount(x);
}
void solve() {
    int tag;
    cin >> tag;
    for (int i = 1; i < 31; i++) {
        int x = i * i * i;
        int a = x * 2;
        int b = a + 1;
        if (check(a) == i) {
            if (a >= tag) {
                cout << a << '\n';
                return;
            }
        }
        if (check(b) == i) {
            if (b >= tag) {
                cout << b << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
}