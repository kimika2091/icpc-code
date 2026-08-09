#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    array <int, 100> num;
    int S;
    Node() {fill(num.begin(), num.end(), 0); S = 0;}
};

array <int, 100> Zero;

struct XorBasis {
    array<Node, 100> basis;
    bool insert(Node x) {
        for (int i = 99; i >= 0; i--) {
            if (x.num[i] == 1) {
                if (basis[i].num == Zero) {
                    basis[i].num = x.num;
                    basis[i].S = x.S;
                    return 1;
                }
                for (int j = 0; j <= 99; j++) {
                    x.num[j] ^= basis[i].num[j]; 
                }
                x.S ^= basis[i].S;
            }
        }
        return 0;
    }
    int query(Node x) {
        for (int i = 99; i >= 0; i--) {
            if (x.num[i] == 1) {
                for (int j = 0; j <= 99; j++) {
                    x.num[j] ^= basis[i].num[j]; 
                }
                x.S ^= basis[i].S;
            }
        }
        if (x.num == Zero) return x.S;
        return -1;
    }
};

void solve() {
    int K;
    cin >> K;
    vector <Node> a(K);
    XorBasis B;
    for (int i = 0; i < K; i++) {
        int C, S;
        cin >> C >> S;
        a[i].S = S;
        while (C--) {
            int L;
            cin >> L;
            L--;
            a[i].num[L] ^= 1;
        }
        B.insert(a[i]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int D;
        cin >> D;
        Node x;
        while (D--) {
            int R;
            cin >> R;
            R--;
            x.num[R] ^= 1;
        }
        cout << B.query(x) << '\n';
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
}