#include<bits/stdc++.h>
using namespace std;
#define int long long

enum Face { UP, DOWN, FRONT, BACK, LEFT, RIGHT };

int best[64];

void init() {
    array<int, 6> first = {1, 6, 2, 5, 3, 4};
    auto rotate_front = [&](const array<int, 6> &cur) -> array<int, 6> {
        return {cur[BACK], cur[FRONT], cur[UP], cur[DOWN], cur[LEFT], cur[RIGHT]};
    };
    auto rotate_left = [&](const array<int, 6> &cur) -> array<int, 6> {
        return {cur[RIGHT], cur[LEFT], cur[FRONT], cur[BACK], cur[UP], cur[DOWN]};
    };
    queue <array<int, 6>> q;
    q.push(first);
    set <array<int, 6>> S;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        auto now = rotate_front(cur);
        if (S.insert(now).second) q.push(now);
        now = rotate_left(cur);
        if (S.insert(now).second) q.push(now);
    }
    for (int i = 0; i < 64; i++) {
        int mx = 0;
        for (auto &cur : S) {
            int sum = 0;
            for (int j = 0; j < 6; j++) {
                if (i >> j & 1) sum += cur[j];
            }
            mx = max(mx, sum);
        }
        best[i] = mx;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> h(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (h[i][j] == 0) continue;
            const array <int, 4> neigbor = {h[i + 1][j], h[i - 1][j], h[i][j - 1], h[i][j + 1]};
            auto get_mask = [&](int H) -> int {
                int mask = 0;
                if (H > neigbor[0]) mask |= 1 << FRONT;
                if (H > neigbor[1]) mask |= 1 << BACK;
                if (H > neigbor[2]) mask |= 1 << LEFT;
                if (H > neigbor[3]) mask |= 1 << RIGHT;
                return mask;
            };
            if (h[i][j] == 1) {
                int mask = get_mask(h[i][j]);
                mask |= 1 << UP;
                mask |= 1 << DOWN;
                ans += best[mask];
                continue;
            }
            int bottom_mask = get_mask(1);
            bottom_mask |= 1 << DOWN;
            ans += best[bottom_mask];
            int top_mask = get_mask(h[i][j]);
            top_mask |= 1 << UP;
            ans += best[top_mask];
            if (h[i][j] >= 3) {
                vector <int> p = {2, h[i][j]};
                for (int H : neigbor) {
                    if (2 < H + 1 && H + 1 < h[i][j]) {
                        p.push_back(H + 1); 
                    }
                }
                sort(p.begin(), p.end());
                p.erase(unique(p.begin(), p.end()), p.end());
                for (int k = 0; k + 1 < p.size(); k++) {
                    int mask = get_mask(p[k]);
                    ans += (p[k + 1] - p[k]) * best[mask];
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    init();
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}