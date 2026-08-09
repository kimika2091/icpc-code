#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

struct Node {
    int cnt, sx, sy, sxy;
};

void add(int &x, int y) {
    x = (x + y) % MOD;
}

void solve() {
    int n, d;
    cin >> n >> d;
    Node dp[2][2] = {};
    dp[0][0].cnt = 1;
    for (int bit = 0; bit <= 60; bit++) {
        Node ndp[2][2] = {};
        int bn = n >> bit & 1;
        int bd = d >> bit & 1;
        for (int carry = 0; carry <= 1; carry++) {
            for (int borrow = 0; borrow <= 1; borrow++) {
                auto &cur = dp[carry][borrow];
                for (int x = 0; x <= 1; x++) {
                    int sum = x + bd + carry;
                    int y = sum & 1;
                    int nc = sum >> 1;
                    int nb = x + borrow > bn;
                    auto &nxt = ndp[nc][nb];
                    add(nxt.cnt, cur.cnt);
                    add(nxt.sx, cur.sx + x * cur.cnt);
                    add(nxt.sy, cur.sy + y * cur.cnt);
                    add(nxt.sxy, cur.sxy + x * cur.sy + y * cur.sx + x * y * cur.cnt);
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    cout << dp[0][0].sxy << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
