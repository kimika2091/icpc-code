#include <bits/stdc++.h>
using namespace std;
#define int long long

const int primes[] = {2, 3, 5, 7, 11};

bool isPrime (int x) {
    if (x == 0 || x == 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1 2" << '\n';
        return;
    }
    if (n == 3) {
        cout << "-1" << '\n';
        return;
    }
    if (n == 4) {
        cout << "-1" << '\n';
        return;
    }
    if (n == 6) {
        cout << "-1" << '\n';
        return;
    }
    if (!isPrime(n - 1)) {
        for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
    }
    else {
        for (int i = 1; i <= n - 4; i++) cout << i << " ";
        for (int i = n; i > n - 4; i--) cout << i << " \n"[i == n - 3];
    }
   
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}