#include <bits/stdc++.h>
using namespace std;

class FastInput {
    static constexpr int S = 1 << 20;
    char buf[S];
    int p = 0, n = 0;

    char getChar() {
        if (p == n) {
            n = (int)fread(buf, 1, S, stdin);
            p = 0;
            if (n == 0) return 0;
        }
        return buf[p++];
    }

public:
    template <class T>
    bool read(T &x) {
        char c;
        do {
            c = getChar();
            if (!c) return false;
        } while (c <= ' ');
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = getChar();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = x * 10 + c - '0';
            c = getChar();
        }
        if (neg) x = -x;
        return true;
    }
};

int main() {
    FastInput in;
    int T = 0;
    in.read(T);
    while (T--) {
        int n = 0, m = 0;
        in.read(n);
        in.read(m);
        vector<long long> a(1LL * n * m);
        for (auto &v : a) in.read(v);

        if (n == 1 || m == 1) {
            bool ok = true;
            for (auto v : a) ok &= v == a[0];
            printf("%d\n", ok ? 0 : -1);
            continue;
        }

        long long base = a[0];
        long long ans = a[1] + a[m] - 2 * base;
        bool ok = ans >= 0 && a.back() == base;

        for (auto &v : a) {
            v = base + ans - v;
            if (v < 0 || v > ans) ok = false;
        }

        for (int d = 0; d <= n + m - 2 && ok; d++) {
            int l = max(0, d - m + 1);
            int r = min(n - 1, d);
            long long sum = 0;
            for (int i = l; i <= r; i++) sum += a[1LL * i * m + d - i];
            if (sum != ans) ok = false;
        }

        for (int d = 0; d < n + m - 2 && ok; d++) {
            int l1 = max(0, d - m + 1);
            int r1 = min(n - 1, d);
            int l2 = max(0, d - m + 2);
            int r2 = min(n - 1, d + 1);
            long long s1 = 0, s2 = 0;
            for (int i = min(l1, l2); i <= max(r1, r2); i++) {
                long long old = s1;
                if (l1 <= i && i <= r1) s1 += a[1LL * i * m + d - i];
                if (l2 <= i && i <= r2) s2 += a[1LL * i * m + d + 1 - i];
                if (s2 < old || s2 > s1) {
                    ok = false;
                    break;
                }
            }
        }

        printf("%lld\n", ok ? ans : -1);
    }
    return 0;
}
