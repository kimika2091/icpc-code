#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SplitMix64Hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + seed);
    }
    template <class A, class B>
    size_t operator()(const pair<A, B>& p) const {
        uint64_t first = splitmix64((uint64_t)p.first);
        uint64_t second = splitmix64((uint64_t)p.second + 0x9e3779b97f4a7c15ULL);
        return (*this)(first ^ second);
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    int N = n * m;
    unordered_map <int, int, SplitMix64Hash> rk;
    int o = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        rk[x] = o++;
    }
    vector <int> b(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        b[i] = rk[x];
    }
    vector <int> low;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(low.begin(), low.end(), b[i]);
        if (it == low.end()) low.push_back(b[i]);
        else *it = b[i];
    }
    cout << N - static_cast<int>(low.size()) << '\n';
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}