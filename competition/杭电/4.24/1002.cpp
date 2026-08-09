#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

struct Node{
    int x, y;
    array<int,7> a;
};

ull Hash(const Node &a) {
    ull h = 0;
    h = h * 0721 + a.x;
    h = h * 0721 + a.y;
    for (int x : a.a) h = h * 0721 + x;
    return h;
}

void solve() {
    int n, m;
    cin >> n >> m;
    array<int, 7> c; 
    for (int i = 1; i <= 6; i++) cin >> c[i];
    auto up = [&](array<int,7> a) { 
        array<int,7> nxt = {0, a[2], a[6], a[3], a[4], a[1], a[5]};
        return nxt;
    };
    auto down = [&](array<int,7> a) {
        array<int,7> nxt = {0, a[5], a[1], a[3], a[4], a[6], a[2]};
        return nxt;
    };
    auto left = [&](array<int,7> a) {
        array<int,7> nxt = {0, a[3], a[2], a[6], a[1], a[5], a[4]};
        return nxt;
    };
    auto right = [&](array<int,7> a) {
        array<int,7> nxt = {0, a[4], a[2], a[1], a[6], a[5], a[3]};
        return nxt;
    };
    unordered_map <ull, int> dis;
    int sx, sy, tx, ty, ct;
    cin >> sx >> sy >> tx >> ty >> ct;
    queue <Node> q;
    Node st = {sx, sy, c};
    ull sh = Hash(st);
    dis[sh] = 0;
    q.push(st);
    while (!q.empty()) {
        auto [x, y, now] = q.front();
        ull h = Hash(q.front());
        q.pop();
        if (x == tx && y == ty && now[6] == ct) {
            cout << dis[h] << '\n';
            return;
        }
        if (x + 1 <= n) {
            Node nxt = {x + 1, y, down(now)};
            ull nh = Hash(nxt);
            if (!dis.count(nh)) {
                dis[nh] = dis[h] + 1;
                q.push(nxt);
            }
        }
        if (x - 1 >= 1) {
            Node nxt = {x - 1, y, up(now)};
            ull nh = Hash(nxt);
            if (!dis.count(nh)) {
                dis[nh] = dis[h] + 1;
                q.push(nxt);
            }
        }
        if (y + 1 <= m) {
            Node nxt = {x, y + 1, right(now)};
            ull nh = Hash(nxt);
            if (!dis.count(nh)) {
                dis[nh] = dis[h] + 1;
                q.push(nxt);
            }
        }
        if (y - 1 >= 1) {
            Node nxt = {x, y - 1, left(now)};
            ull nh = Hash(nxt);
            if (!dis.count(nh)) {
                dis[nh] = dis[h] + 1;
                q.push(nxt);
            }
        } 
    }
    cout << -1 << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}