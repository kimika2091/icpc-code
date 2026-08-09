#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1000005;

string a;
ll one[N], onepos[N], zeropos[N];
int n, q;

ll getans(int l, int r) {
    int m = one[r] - one[l - 1];
    // \sum_{i=m+1}^{n} '+' pos: [l+m, r]
    long long res1 = onepos[r] - onepos[l + m - 1] - 1ll * (l - 1) * (one[r] - one[l + m - 1]);
    // \sum_{i=1}^{m} '-' pos: [l, l+m-1]
    long long res2 = zeropos[l + m - 1] - zeropos[l - 1] - 1ll * (l - 1) * (m - (one[l + m - 1] - one[l - 1]));
    assert(1ll * (l - 1) * (one[r] - one[l + m - 1]) == 1ll * (l - 1) * (m - (one[l + m - 1] - one[l - 1])));
    return m + 2 * (res1 - res2);
}

void sc() {
    cin >> n >> q >> a;
    a = ' ' + a;

    for (int i = 1; i <= n; i++) {
        one[i] = one[i - 1] + (a[i] == '+');
        onepos[i] = onepos[i - 1] + (a[i] == '+') * i;
        zeropos[i] = zeropos[i - 1] + (a[i] == '-') * i;
    }

    long long ans = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        assert(1 <= l && l <= r && r <= n);
        // printf("%lld\n", getans(l, r));
        ans ^= getans(l, r);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) sc();
    return 0;
}