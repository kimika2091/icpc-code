## G

循环左移 $x$ 位后的字符串 $A'$ 满足 $A_i'=A_{(i+x)\,\mathrm{mod}\,n}$。若 $A'$ 为回文串，则 $A'_i=A'_{n-1-i}$，所以 $A_{(i+x)\,\mathrm{mod}\,n}=A_{(-1-i+x)\,\mathrm{mod}\,n}$。令 $j=(i+x)\,\mathrm{mod}\,n$。则 $A_j=A_{(-1-j+2x)\,\mathrm{mod}\,n}$。由题意知式子对于任意 $x=k\cdot d$ 都成立。记第 $k$ 个条件为 $P_k:A_j=A_{(-1-j+2kd)\,\mathrm{mod}\,n}$

先考虑 $k=0$ 和 $k=1$ 的情况，可以得到 $A_j=A_{(-1-j)\,\mathrm{mod}\,n}$ 和 $A_j=A_{(-1-j+2d)\,\mathrm{mod}\,n}$

结合这两个式子我们能够得到 $A_j=A_{(j+2d)\,\mathrm{mod}\,n}$。容易发现条件 $A_j=A_{(-1-j)\,\mathrm{mod}\,n}$ 加上 $A_j=A_{(j+2d)\,\mathrm{mod}\,n}$ 就能推出 $P_k$。所以，只需要满足这两个条件就能满足所有的 $P_k$。

条件 $A_j=A_{(j+2d)\,\mathrm{mod}\,n}$ 将下标划分成 $g=\gcd(2d,n)$ 个剩余类。再考虑条件 $A_j=A_{(-1-j)\,\mathrm{mod}\,n}$。假设位置 $j$ 模 $g$ 的余数是 $r$，所以有 $j\equiv -1-j\equiv -1-r\,(\mathrm{mod}\,g)$。所以剩余类 $C_r$ 需要与 $C_{-1-r}$ 合并。

对于每个剩余类，我们保留其中出现次数最多的字符，修改其余字符。

```cpp
void solve() {
	int n, d;
	cin >> n >> d;
	string a;
	cin >> a;
	int g = gcd(n, 2 * d);
	vector <vector<int>> p(n + 1);
	for (int i = 0; i < n; i++) {
		int j = min(i % g, ((- 1 - i) % g + g) % g);
		p[j].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < g; i++) {
		vector <int> cnt(26, 0);
		for (int &x : p[i]) cnt[a[x] - 'a']++;
		ans += p[i].size() - *max_element(cnt.begin(), cnt.end());
	}
	cout << ans << '\n';
}
```

## J

考虑 dp。

定义 $f_i$ 为前 $i$ 个位置合法划分的方案数。

容易写出转移方程：

$$f_i=\sum_{[j+1,i]\text{合法}} f_j$$

所以问题变成：固定右端点 $i$，快速找到所有使 $[j+1,i]$ 合法的 $j$。

一段序列是合法的当且仅当所有数字的出现次数模 4 等于 0。这里有个小 trick，可以用 Hash 快速判断前缀数字出现次数模 4 的状态。这样只需要满足 $h_i=h_j$ 就能转移。

但同时需要注意，一段序列中任何数字出现的次数都不能大于 4 次。我们需要记录一个指针来维护左端点的范围。

使用 Hash 表能做到优秀的 $\mathcal{O}(n)$。

```cpp
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count()
    );
    vector<array<ULL, 4>> rnd(n + 1);
    for (int x = 1; x <= n; x++) {
        rnd[x][0] = 0;
        for (int r = 1; r < 4; r++) {
            rnd[x][r] = rng();
        }
    }
    
    vector<int> r(n + 1), dp(n + 1);
    vector<vector<int>> o(n + 1);
    vector<ULL> h(n + 1);
    unordered_map<ULL, int> sum;
    sum.reserve(2 * n + 10);
    sum.max_load_factor(0.7);
    dp[0] = 1;
    h[0] = 0;
    sum[h[0]] = 1;
    int lim = 0, left = 0;
    ULL cur = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        cur ^= rnd[x][r[x]];
        r[x] = (r[x] + 1) % 4;
        cur ^= rnd[x][r[x]];
        h[i] = cur;
        o[x].push_back(i);
        int k = o[x].size();
        if (k >= 5) {
            lim = max(lim, o[x][k - 5]);
        }
        while (left < lim) {
            int &val = sum[h[left]];
            val -= dp[left];
            if (val < 0) val += MOD;
            left++;
        }
        dp[i] = sum[h[i]];
        int &val = sum[h[i]];
        val += dp[i];
        if (val >= MOD) val -= MOD;
    }
    cout << dp[n] << '\n';
}
```

我赛时的做法是使用线段树维护左端点。定义不合法序列的 $val$ 值大于 0，合法序列的 $val$ 值等于 0。维护 $val$ 的最小值，并维护所有 $val = mn$ 的叶子的 $dp_{l-1}$ 之和。复杂度 $\mathcal{O}n\log n$。

```cpp
struct SegmentTree {
    int n;
    vector<int> sum, mn, lazy;
    SegmentTree(int n) : n(n), sum(4 * n + 1, 0), mn(4 * n + 1, INF), lazy(4 * n + 1, 0) {}
    void push_up(int node) {
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        sum[node] = 0;
        if (mn[node] == mn[node * 2]) sum[node] += sum[node * 2];
        if (mn[node] == mn[node * 2 + 1]) sum[node] += sum[node * 2 + 1];
        sum[node] %= MOD;
    }
    void push_down(int node) {
        if (lazy[node] != 0) {
            mn[node * 2] += lazy[node];
            lazy[node * 2] += lazy[node]; 
            mn[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 1] += lazy[node]; 
            lazy[node] = 0;
        }
    }
    void change(int node, int l, int r, int x, int val) {
        if (l == r) {
            mn[node] = 0;
            lazy[node] = 0;
            sum[node] = val % MOD;
            return;
        }
        push_down(node);
        int mid = (l + r) / 2;
        if (x <= mid) change(node * 2, l, mid, x, val);
        else change(node * 2 + 1, mid + 1, r, x, val);
        push_up(node);
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql > qr) return;
        if (ql <= l && r <= qr) {
            mn[node] += val;
            lazy[node] += val;
            return;
        }
        push_down(node);
        int mid = (l + r) / 2;
        if (ql <= mid) update(node * 2, l, mid, ql, qr, val);
        if (qr > mid) update(node * 2 + 1, mid + 1, r, ql, qr, val);
        push_up(node);
    }
};

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), dp(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] % 4 != 0) {
            cout << 0 << '\n';
            return;
        }
        cnt[i] = 0;
    }
    vector <vector<int>> lst(n + 1, vector<int>(5));
    dp[0] = 1;
    SegmentTree tr(n + 1);
    for (int r = 1; r <= n; r++) {
        tr.change(1, 1, n, r, dp[r - 1]);
        tr.update(1, 1, n, lst[a[r]][0] + 1, r, 1);
        if (lst[a[r]][2]) {
            tr.update(1, 1, n, lst[a[r]][3] + 1, lst[a[r]][2], -1);
        }
        if (lst[a[r]][3]) {
            tr.update(1, 1, n, lst[a[r]][4] + 1, lst[a[r]][3], 1);
        }
        for (int i = 4; i >= 1; i--) lst[a[r]][i] = lst[a[r]][i - 1];
        lst[a[r]][0] = r;
        dp[r] = tr.mn[1] == 0? tr.sum[1] : 0;
    }
    cout << dp[n] << '\n';
}
```

## K

签到。

## C

显然答案不会超过 2。如果序列已经非降，则答案为 0。如果存在子序列 $2,1,0$，则答案为 2。其余情况答案为 1。

我们可以用线段树维护序列信息。写起来不算太难，具体可以见代码。

~~最喜欢数据结构了喵呜♥♥♥~~

```cpp
struct Node {
    int mask = 0;
    bool s10 = false;
    bool s20 = false;
    bool s21 = false;
    bool s210 = false;
};

bool has(const Node& x, int value) {
    return (x.mask >> value) & 1;
}

Node merge(const Node& L, const Node& R) {
    Node res;
    res.mask = L.mask | R.mask;
    res.s10 = L.s10 || R.s10 || (has(L, 1) && has(R, 0));
    res.s20 = L.s20 || R.s20 || (has(L, 2) && has(R, 0));
    res.s21 = L.s21 || R.s21 || (has(L, 2) && has(R, 1));
    res.s210 = L.s210 || R.s210 || (L.s21 && has(R, 0)) || (has(L, 2) && R.s10);
    return res;
}

Node makeNode(int value) {
    Node res;
    res.mask = 1 << value;
    return res;
}

struct SegmentTree {
    int size;
    vector<Node> tree;
    SegmentTree(const vector<int>& a) {
        int n = a.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(size * 2);
        for (int i = 0; i < n; ++i) {
            tree[size + i] = makeNode(a[i]);
        }
        for (int i = size - 1; i >= 1; --i) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }
    void update(int pos, int value) {
        int p = size + pos;
        tree[p] = makeNode(value);
        for (p >>= 1; p >= 1; p >>= 1) {
            tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
        }
    }
    Node query(int l, int r) {
        l += size;
        r += size;
        Node L, R;
        while (l <= r) {
            if (l & 1) L = merge(L, tree[l++]);
            if (!(r & 1)) R = merge(tree[r--], R);
            l >>= 1;
            r >>= 1;
        }
        return merge(L, R);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    SegmentTree seg(a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            seg.update(p, x);
        } 
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            Node res = seg.query(l, r);
            bool sorted = !res.s10 && !res.s20 && !res.s21;
            if (sorted) cout << 0 << '\n';
            else if (res.s210) cout << 2 << '\n';
            else cout << 1 << '\n';         
        }
    }
}
```