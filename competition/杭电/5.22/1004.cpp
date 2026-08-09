#include <bits/stdc++.h>
using namespace std;
#define int long long
const string t = "execute";
struct Node {
    int L, M, R;
    bool operator < (const Node &others) const {
        return L > others.L;
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector <Node> p;
    for (int i = 0; i + 6 < n; i++) {
        string cur = "";
        for (int j = i; j <= i + 6; j++) cur += s[j];
        if (cur == t) p.push_back({i, i + 2, i + 6});
    }
    vector <bool> tag(n, 0);
    sort(p.begin(), p.end());
    for (auto &[L, M, R] : p) {
        if (!tag[L] && !tag[M] && !tag[R]) tag[L] = 1;
    }
    for (int i = 0; i < n; i++) cout << (tag[i] ? '1' : s[i]);
    cout << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
