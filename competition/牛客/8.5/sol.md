## D

无向图上的一条路径可以通过在任意一条边上来回走，使长度增加 $2$。因此只需要求出从 $1$ 到每个点的最短奇数长度和最短偶数长度。把每个点拆成奇偶两个状态，跑一次 BFS 即可。

接下来寻找不小于最短长度的最小 $k$ 的倍数，并保证奇偶性不变。当 $k$ 为偶数时，它的倍数只能是偶数；当 $k$ 为奇数时，$cnt\cdot k$ 与 $cnt$ 奇偶性相同，调整 $cnt$ 的奇偶性即可。时间复杂度 $\mathcal{O}(n+m)$。

```cpp
const int INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <vector<int>> dis(n + 1, vector<int>(2, INF));
    queue <pair<int, int>> q;
    dis[1][0] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        auto [u, s] = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (dis[v][s ^ 1] == INF) {
                dis[v][s ^ 1] = dis[u][s] + 1;
                q.push({v, s ^ 1});
            }
        }
    }
    auto calc = [&](int x, int y) -> int {
        if (x == INF && y == INF) return -1;
        if (y == 0) return 0;
        if (k == 1) return min(x, y);
        if (k & 1) {
            if (x != INF) {
                int cnt = (x + k - 1) / k;
                if (!(cnt & 1)) cnt++;
                x = cnt * k;
            }
            if (y != INF) {
                int cnt = (y + k - 1) / k;
                if (cnt & 1) cnt++;
                y = cnt * k;
            }
            return min(x, y);
        }
        else {
            if (y == INF) return -1;
            return (y + k - 1) / k * k;
        }
    };
    for (int i = 1; i <= n; i++) {
        cout << calc(dis[i][1], dis[i][0]) << " \n"[i == n];
    }
}
```

## F

对于每个真后缀 $s[i\ldots n-1]$，使用 Z 函数求出它与 $s$ 的最长公共前缀 $z_i$。如果 $i+z_i=n$，说明这个后缀是 $s$ 的真前缀，它一定比 $s$ 小，答案为 $0$。否则第一次不同的位置要求

$$
s_{z_i}<s_{i+z_i}.
$$

把字母看作点，上式看作有向边，就得到了一个偏序。合法字母表与这个图的拓扑序一一对应，问题变成统计 $26$ 个点的拓扑序数量。

设 $dp(S)$ 表示点集 $S$ 的拓扑序数量。如果 $S$ 能拆成多个弱连通块，分别计算后用组合数交错合并；如果只有一个入度为 $0$ 的点，则它必须排在最前面；否则枚举放在最前面的点。所有运算使用 `uint32_t`，溢出正好等价于对 $2^{32}$ 取模。时间复杂度为 $\mathcal{O}(n+26\cdot 2^{26})$，实际状态数会被连通块分解大幅减少。

```cpp
array <uint32_t, 26> pre, e;
array <array<uint32_t, 27>, 27> C;
unordered_map <uint32_t, uint32_t> dp;

uint32_t mul(uint32_t x, uint32_t y) {
    return uint32_t(uint64_t(x) * y);
}

uint32_t dfs(uint32_t S) {
    if (__builtin_popcount(S) <= 1) return 1;
    if (dp.count(S)) return dp[S];

    vector <uint32_t> parts;
    uint32_t rest = S;
    while (rest) {
        uint32_t cur = rest & -rest;
        uint32_t part = 0;
        while (cur) {
            part |= cur;
            uint32_t nxt = 0;
            uint32_t t = cur;
            while (t) {
                int x = __builtin_ctz(t);
                t &= t - 1;
                nxt |= e[x];
            }
            cur = nxt & S & ~part;
        }
        parts.push_back(part);
        rest &= ~part;
    }

    if (parts.size() > 1) {
        uint32_t ans = 1;
        int sum = 0;
        for (auto &part : parts) {
            int sz = __builtin_popcount(part);
            ans = mul(ans, C[sum + sz][sz]);
            ans = mul(ans, dfs(part));
            sum += sz;
        }
        return dp[S] = ans;
    }

    uint32_t source = 0;
    uint32_t t = S;
    while (t) {
        int x = __builtin_ctz(t);
        t &= t - 1;
        if ((pre[x] & S) == 0) source |= uint32_t(1) << x;
    }
    if (source == 0) return dp[S] = 0;
    if ((source & (source - 1)) == 0) return dp[S] = dfs(S ^ source);

    uint32_t ans = 0;
    while (source) {
        uint32_t x = source & -source;
        source &= source - 1;
        ans += dfs(S ^ x);
    }
    return dp[S] = ans;
}

void solve() {
    C[0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    string s;
    cin >> s;
    int n = s.size();
    vector <int32_t> z(n);
    pre.fill(0);
    e.fill(0);
    dp.clear();

    int l = 0, r = -1;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min<int>(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (i + z[i] == n) {
            cout << 0 << '\n';
            return;
        }
        int x = s[z[i]] - 'a';
        int y = s[i + z[i]] - 'a';
        pre[y] |= uint32_t(1) << x;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (pre[j] >> i & 1) {
                e[i] |= uint32_t(1) << j;
                e[j] |= uint32_t(1) << i;
            }
        }
    }

    cout << dfs((uint32_t(1) << 26) - 1) << '\n';
}
```

## G

定义安全点集 $S$。特殊点初始都在 $S$ 中；如果一个非特殊点有至少两个邻点在 $S$ 中，也把它加入 $S$。使用队列维护每个点的安全邻点数量即可。

当 Alice 到达一个新加入的安全点时，它有两条通向更早安全点的边，Bob 一次至多删除其中一条。由于点的度数不超过 $3$，递归选出的两棵策略子树边不相交，Bob 提前删除的边也至多破坏一个分支，Alice 选择另一个分支即可。

反过来，在 $V\setminus S$ 中，每个点至多只有一个安全邻点。若起点不与 $S$ 相邻，Alice 每次走到新点后，Bob 删除它唯一可能通向 $S$ 的边，就能一直把 Alice 留在 $V\setminus S$ 中。

Alice 第一次移动前 Bob 还没有删边，所以答案就是所有与 $S$ 相邻的非特殊点。时间复杂度 $\mathcal{O}(n+m)$。

```cpp
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> a(n + 1), s(n + 1);
    queue <int> q;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        a[x] = 1;
        s[x] = 1;
        q.push(x);
    }
    vector <int> cnt(n + 1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int &y : g[x]) {
            if (a[y] == 1) continue;
            cnt[y]++;
            if (cnt[y] == 2) {
                a[y] = 1;
                q.push(y);
            }
        }
    }
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 0) {
            bool ok = 0;
            for (int &j : g[i]) {
                if (a[j]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int &x : ans) cout << x << ' ';
    cout << '\n';
}
```

## H

相邻整数之差为 $1$，不是质数。因此字典序最小的候选显然是 $1,2,\ldots,n$，它只有首尾之差 $n-1$ 可能不合法。如果 $n-1$ 不是质数，直接输出自然排列。

如果 $n-1$ 是质数且 $n\ge 8$，保留尽量长的自然排列前缀，把最后四个数改成

$$
n,n-1,n-2,n-3.
$$

新产生的差依次为 $4,1,1,1,n-4$。此时 $n$ 是偶数且 $n\ge 8$，所以 $n-4$ 也是不小于 $4$ 的偶数，构造合法。直接检查较小的情况可知 $n=3,4,6$ 无解。时间复杂度 $\mathcal{O}(n)$。

```cpp
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
```

## I

从低位到高位枚举 $i$ 的每一位。这样可以自然维护 $i+d$ 的进位。为了同时限制 $i\le n$，再维护二进制减法 $n-i$ 的借位，处理完所有位后没有借位，当且仅当 $i\le n$。

设当前已经处理的位中，$i$ 的 `popcount` 为 $x$，$i+d$ 的 `popcount` 为 $y$。每个进位和借位状态维护方案数、$x$ 之和、$y$ 之和以及 $xy$ 之和。加入的新二进制位分别为 $a,b$ 时，有

$$
(x+a)(y+b)=xy+ay+bx+ab.
$$

按照这个式子更新四个量即可。由于 $n,d<2^{60}$，处理第 $0$ 到第 $60$ 位就能消除最后的进位。每个测试用例的时间复杂度为 $\mathcal{O}(\log(n+d))$，空间复杂度为 $\mathcal{O}(1)$。

```cpp
const int mod = 998244353;

struct Node {
    int cnt, sx, sy, sxy;
};

void add(int &x, int y) {
    x = (x + y) % mod;
}

void solve() {
    int n, d;
    cin >> n >> d;
    Node dp[2][2] = {};
    dp[0][0].cnt = 1;
    for (int bit = 0; bit <= 60; bit++) {
        Node ndp[2][2] = {};
        int bn = n >> bit & 1;
        int bd = d >> bit & 1;
        for (int carry = 0; carry <= 1; carry++) {
            for (int borrow = 0; borrow <= 1; borrow++) {
                auto &cur = dp[carry][borrow];
                for (int x = 0; x <= 1; x++) {
                    int sum = x + bd + carry;
                    int y = sum & 1;
                    int nc = sum >> 1;
                    int nb = x + borrow > bn;
                    auto &nxt = ndp[nc][nb];
                    add(nxt.cnt, cur.cnt);
                    add(nxt.sx, cur.sx + x * cur.cnt);
                    add(nxt.sy, cur.sy + y * cur.cnt);
                    add(nxt.sxy, cur.sxy + x * cur.sy + y * cur.sx + x * y * cur.cnt);
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    cout << dp[0][0].sxy << '\n';
}
```
