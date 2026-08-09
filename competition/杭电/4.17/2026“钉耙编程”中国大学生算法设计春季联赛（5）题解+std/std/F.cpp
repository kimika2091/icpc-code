#include <bits/stdc++.h>
using namespace std;

int lb[128], pcnt[128], XX1[128], XX2[128], YY1[128], YY2[128];

int X1[100005], X2[100005], Y1[100005], Y2[100005];
int a[1005][1005];
int pre[1005][1005][8];
int n, q;

void sc() {
    memset(a, 0, sizeof(a));
    memset(pre, 0, sizeof(pre));
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        X1[i] = x1, X2[i] = x2, Y1[i] = y1, Y2[i] = y2;
        a[x1][y1]++;
        a[x1][y2 + 1]--;
        a[x2 + 1][y1]--;
        a[x2 + 1][y2 + 1]++;
    }
    int res = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
            if (a[i][j]) res++;
            for (int k = 0; k <= 7; k++) {
                pre[i][j][k] = pre[i][j - 1][k] + pre[i - 1][j][k] - pre[i - 1][j - 1][k];
                if (a[i][j] <= k)
                    pre[i][j][k]++;
            }
        }
    }
    // printf("res = %d\n", res);
    while (q--) {
        static int k, id[8]; cin >> k;
        for (int i = 0; i < k; i++) cin >> id[i];
        XX1[0] = 0, XX2[0] = 1000, YY1[0] = 0, YY2[0] = 1000;
        int ans = res;
        for (int st = 1; st < 1 << k; st++) {
            XX1[st] = max(XX1[st ^ 1 << lb[st]], X1[id[lb[st]]]);
            XX2[st] = min(XX2[st ^ 1 << lb[st]], X2[id[lb[st]]]);
            YY1[st] = max(YY1[st ^ 1 << lb[st]], Y1[id[lb[st]]]);
            YY2[st] = min(YY2[st ^ 1 << lb[st]], Y2[id[lb[st]]]);
            if (XX1[st] <= XX2[st] && YY1[st] <= YY2[st]) {
                ans -= pre[XX2[st]][YY2[st]][pcnt[st]] - 
                       pre[XX1[st] - 1][YY2[st]][pcnt[st]] - 
                       pre[XX2[st]][YY1[st] - 1][pcnt[st]] +
                       pre[XX1[st] - 1][YY1[st] - 1][pcnt[st]];
            }
        }
        // printf("%d\n", ans);
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    for (int st = 1; st < 128; st++) {
        for (int i = 0; i < 7; i++)
            if (st >> i & 1) {
                lb[st] = i;
                break;
            }
        pcnt[st] = __builtin_popcount(st);
    }
    int T; cin >> T;
    while (T--) sc();
    return 0;
}