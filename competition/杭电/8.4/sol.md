## E

维护每个字符串是否连续 $k$ 次出现，第一次出现的位置，和出现总次数即可。比较签到。

```cpp
void solve() {
    int n, k, m, q;
    cin >> n >> k >> m >> q;
    vector <int> ans;
    vector<string> s(n);
    set <string> S;
    map <string, int> idx;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        S.insert(s[i]);
    }
    int o = 0;
    for (auto &x : S) {
        idx[x] = o++;
    }
    vector <int> first(o, -1), cnt(o), can(o);
    auto check1 = [&](const string &t, int i, int x) -> bool {
        if (i < k) return 0;
        if (can[x]) return 1;
        for (int j = i - 1; j >= i - k; j--) {
            if (t != s[j]) {
                return 0;
            }
        }
        can[x] = 1;
        return 1;
    };
    auto update = [&](const string &t, int i, int x) -> void {
        if (i - k + 1 < 0) return;
        if (can[x]) return;
        for (int j = i; j >= i - k + 1; j--) {
            if (t != s[j]) {
                return;
            }
        }
        can[x] = 1;
    };
    auto check2 = [&](int x, int i) -> bool {
        if (first[x] == -1) return 0;
        return i - first[x] > m;
    };
    for (int i = 0; i < n; i++) {
        int cur = idx[s[i]];
        if (cnt[cur] == q) continue;
        if (check1(s[i], i, cur) && check2(cur, i)) ans.push_back(i + 1);
        if (cnt[cur] == 0) first[cur] = i;
        cnt[cur]++;
        update(s[i], i, cur);
    }
    if (ans.empty()) cout << "empty" << '\n';
    else {
        for (auto &x: ans) cout << x << ' ';
        cout << '\n';
    }
}
```
## H

经典二维数点。我们把 $L$ 看作横坐标轴，$R$ 看作纵坐标轴，每一段区间 $[l_i,r_i]$ 看作平面上的点，点的权值为 $r_i-l_i+1$。则一次询问就是要找到在矩形 $L\le l_i,r_i\le R$ 中的最大点权。

离线操作，把询问和点按左端点从大到小排序，在左端点 $l_i \ge L$ 的情况下，将点插入树状数组。维护右端点 $r_i\le R$ 的最大权值。由于值域很大，需要离散化。时间复杂度 $\mathcal{O}(n\log n + q\log(n+q))$

```cpp
struct Segment {
    int l, r;
    int len() const { return r - l + 1; }
    bool operator < (const Segment &other) const {
        return l > other.l;
    }
};
struct Query {
    int l, r;
    int id;
    bool operator < (const Query &other) const {
        return l > other.l;
    }
};
struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void update(int x, int v) {
        for (int i = x; i <= n; i += i & -i) {
            t[i] = max(t[i], v);
        }
    }
    int query(int x) const {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res = max(res, t[i]);
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector <Segment> points(n);
    vector <int> Rs(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].l >> points[i].r;
        Rs[i] = points[i].r;
    }
    sort(Rs.begin(), Rs.end());
    Rs.erase(unique(Rs.begin(), Rs.end()), Rs.end());
    vector <Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }
    sort(points.begin(), points.end());
    sort(queries.begin(), queries.end());
    vector <int> ans(q);
    BIT bit(Rs.size());
    int ptr = 0;
    for (auto &[L, R, id] : queries) {
        while (ptr < n && points[ptr].l >= L) {
            int len = points[ptr].len();
            int x = lower_bound(Rs.begin(), Rs.end(), points[ptr].r) - Rs.begin() + 1;
            bit.update(x, len);
            ptr++;
        }
        int x = upper_bound(Rs.begin(), Rs.end(), R) - Rs.begin();
        ans[id] = bit.query(x);
    }
    for (auto &x : ans) cout << x << '\n';
}
```



## J

把一个局面映射成 100 位的二进制数字。把所有局面都放到异或线性基里，对应的权值也同时异或处理。看最终询问的局面能否被线性基所表示。时间复杂度 $\mathcal{O}(100 \cdot 100 \cdot n)$

```cpp
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
```

