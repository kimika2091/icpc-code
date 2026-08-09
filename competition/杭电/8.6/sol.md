## J

首先注意到序列的末尾一定是蓝色牌。因为若最后是红色牌收益是 $0$。

设第 $i$ 张红牌前打出 $b_i$ 张蓝牌，剩余蓝牌放到所有红牌之后。

令 $z=\sum_{i=1}^y b_i$ 表示用于强化红牌的蓝牌总数。

则总伤害 $D=\sum_{i=1}^{y}(b_i+1)(x+y-i-\sum_{j=1}^ib_j)$

整理一下能够得到 $D=xy+\dfrac{y(y-1)}{2}+z(x-1)-\dfrac{z^2+\sum_{i=1}^y b_i^2}{2}$。

固定使用 $z$ 张蓝牌时，其他部分已经确定，只需要最小化 $\sum b_i^2$。

显然蓝牌应该尽量平均分给 $y$ 张红牌。

设 $z=qy+r\,(0\le r<y)$，则有 $y-r$ 个 $b_i=q$，$r$ 个 $b_i=q+1$。

所以 $\min\sum b_i^2=(y-r)q^2+r(q+1)^2$。

我们现在只需要确定最优的 $z$。

设使用 $z$ 张蓝牌时的最优伤害为 $F(z)$。再增加一张蓝牌，伤害变化为 $\Delta(z)=F(z+1)-F(z)=x-2-z-\lfloor\dfrac{z}{y}\rfloor$。

显然，这是一个关于 $z$ 单调递减的函数。所以取第一个满足 $\Delta(z)\le 0$ 的 $z$。

我们只需要求 $z+\lfloor\dfrac{z}{y}\rfloor\ge x-2$ 的最小整数解。

简单推导下吧：

首先能得到 $q(y+1)+r\ge x-2$。

设 $x-2=t(y+1)+s \,(0\le s<y+1)$

分情况讨论。若 $0\le s<y$，直接取到等号，即 $q=t,r=s$。此时 $z=qy+r=ty+s=x-2-t=x-2-\lfloor\dfrac{x-2}{y+1}\rfloor$。

若 $s=y$，只能考虑进位。取 $q=t+1,r=0$。此时 $z=qy+r=(t+1)y=x-2-t=x-2-\lfloor\dfrac{x-2}{y+1}\rfloor$。

所以这两种情况能统一起来。

注意：$x<2$ 时取 $z=0$；特判 $y=0$ 时答案为 $0$。

总时间复杂度 $\mathcal{O}(1)$。

```cpp
void solve() {
    int x, y;
    cin >> x >> y;
    if (y == 0) {
        cout << 0 << '\n';
        return;
    }
    int z = 0;
    if (x >= 2) z = x - 2 - (x - 2) / (y + 1);
    int q = z / y, r = z % y;
    int ans = x * y + y * (y - 1) / 2 + z * (x - 1) - (z * z + (y - r) * q * q + r * (q + 1) * (q + 1)) / 2;
    cout << ans << '\n';
}
```

## L

发现每个点的产生的贡献最终一定会到达根节点，但是可能会有延迟。设 $d_i$ 是 $A_i$ 的贡献到达根所需的额外轮数。沿着 $u$ 到根的路径，每经过一条满足 $f_v<v\,(f_v\ne1)$ 的边，延迟增加 $1$。递推式为：$d_v=d_{f_v}+[f_v\ne1\land f_v<v]$。

所以最终的答案为 $B_1=\sum_{i=2}^{n}A_i(M-d_i)$。

展开后得到 $B_1=M\sum_{i=2}^{n}A_i-\sum_{i=2}^{n}A_id_i$。

由于总轮数 $M=998^{244^{353}}$ 十分巨大。所以 $B_1$ 的符号主要由 $\sum_{i=2}^n A_i$ 决定。若 $\sum_{i=2}^n A_i=0$，再去看 $\sum_{i=2}^{n}A_id_i$ 的符号。

时空复杂度都是 $\mathcal{O}(n)$。

```cpp
void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), f(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) sum += a[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> f[i];
    }
    if (sum != 0) {
        cout << (sum > 0 ? 1 : -1) << '\n';
        return;
    }
    vector <vector<int>> g(n + 1);
    vector <int> d(n + 1);
    for (int i = 2; i <= n; i++) {
        g[f[i]].push_back(i);
    }
    auto dfs = [&](auto &self, int x) -> void {
        for (int &y : g[x]) {
            d[y] = d[x] + (x != 1 && x < y); 
            self(self, y);
        }
    };
    dfs(dfs, 1);
    sum = 0;
    for (int i = 2; i <= n; i++) {
        sum += a[i] * d[i];
    }
    if (sum == 0) cout << sum << '\n';
    else cout << (sum > 0 ? -1 : 1) << '\n';
}
```













