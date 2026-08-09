#include <bits/stdc++.h>
using namespace std;

void print(__int128 ans) {
    if (ans >= 10) print(ans / 10);
    putchar(ans % 10 + '0');
}

void sc() {
    long long n;
    __int128 ans = 0;
    cin >> n;
    for (int k = 1; (1ll << k) <= n; k++) {
        __int128 up = n >> k;
        ans += up * (n + 1) - up * (up + 1) / 2 * (1ll << k);
    }
    print(ans), putchar('\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) sc();
    return 0;
}