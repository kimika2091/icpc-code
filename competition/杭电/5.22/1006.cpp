#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int N = 10000005;

int phi[N];
bool vis[N];
vector<int> primes;

void precompute_phi() {
    phi[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes) {
            if (i * p >= N) break;
            vis[i * p] = true;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
}

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll gauss_det(vector<vector<ll>>& mat, int n) {
    ll det = 1;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (mat[j][i] > mat[pivot][i]) pivot = j;
        }
        if (pivot != i) {
            swap(mat[i], mat[pivot]);
            det = (MOD - det) % MOD;
        }
        if (mat[i][i] == 0) return 0; 

        det = (det * mat[i][i]) % MOD;
        ll inv = power(mat[i][i], MOD - 2);
        for (int j = i + 1; j < n; j++) {
            ll factor = (mat[j][i] * inv) % MOD;
            for (int k = i; k < n; k++) {
                mat[j][k] = (mat[j][k] - factor * mat[i][k] % MOD + MOD) % MOD;
            }
        }
    }
    return det;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    if (n > 100) {
        cout << 0 << "\n";
        return;
    }
    vector<vector<ll>> mat(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll xor_val = a[i] ^ b[j];
            ll phi_sum = (phi[a[i]] + phi[b[j]]) % MOD;
            mat[i][j] = (xor_val % MOD) * phi_sum % MOD;
        }
    }

    cout << gauss_det(mat, n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute_phi();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}