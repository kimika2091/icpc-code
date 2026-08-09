#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int s1, s2;
    cin >> s1 >> s2;
    auto calc = [&]() -> double {
        if (s2 < 45) return 0;
        int s = ceil(0.6 * s1 + 0.4 * s2);
        if (s >= 95) return 5;
        if (s >= 60) return 5 - 0.1 * (95 - s);
        return 0; 
    };
    cout << fixed << setprecision(1) << calc() << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}