昨天那场被队友麻麻们带飞了，今天终于发力了喵。

北京这两天怎么老突然下暴雨啊，刚打完比赛出门就被淋了，这周被淋的第二次。

## L

设 $a \equiv r\,(\mathrm{mod}\,b)$，则 $a\equiv r
+1\,(\mathrm{mod}\,b+1)$。

因为 $\gcd(b,b+1)=1$，若 $r$ 固定，由 CRT 可知：$a$ 在模 $M=b(b+1)$ 意义下有唯一解 $a=r(b+1)+(r+1)b(-1)=r-b$。

所以 $a$ 的通解是 $a=mb(b+1)+r-b$。其中 $0\le r < b$。我们还需要满足 $1\le a\le n$ 的条件。当 $m=1,r=0$ 时得到最小合法解 $a=b^2$。所以我们可以 $\mathcal{O}(\sqrt{n})$ 枚举 $b$。对于每一个 $b$ 累加贡献 $\lfloor\dfrac{n}{b(b+1)}\rfloor b+\max(0,\,n\,\mathrm{mod}\,b(b+1)-b^2+1)$。

## K

字符串模拟，签到题。

## G

大力手玩样例，发现若出现 $4$ 种及以上数字的情况一定不合法。

## A

首先我们发现，每一次操作 $k$ 一定取 $2$ 的整数次幂，因为这样能够处理的位更灵活，而且总代价不变。其次，从高位往低位贪心考虑，对于某一位，我们肯定尽量避免花费代价。可以维护一个不改变位的集合 $S$。每次尝试不改变当前位。对于 check，继续考虑贪心构造。由于最终需要保证序列单调不下降，我们要让起点最低，然后在满足当前数字大于等于上一个数字的前提下，尽量让当前数最小。时间复杂度 $\mathcal{O}(n\log^2n)$。

```cpp
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    int full = (1LL << 30) - 1;
    auto can = [&](int &cur, int lst, int yes) -> bool {
        for (int i = 29; i >= 0; i--) {
            if (yes & (1LL << i)) {
                if (!(cur & (1LL << i))) cur += (1LL << i);
            }
        }
        if (lst > cur) return false; 
        if (lst == cur) return true;
        for (int i = 29; i >= 0; i--) {
            if (yes & (1LL << i)) {
                if (cur & (1LL << i)) {
                    if (cur - (1LL << i) >= lst) {
                        cur -= (1LL << i);
                    }
                }
            }
        }
        return true;
    };
    auto check = [&](int no) -> bool {
        int yes = full ^ no;
        vector <int> b = a;
        for (int i = 29; i >= 0; i--) {
            if (yes & (1LL << i)) {
                if (b[0] & (1LL << i)) b[0] -= (1LL << i);
            }
        }
        for (int i = 1; i < n; i++) {
            if (!can(b[i], b[i - 1], yes)) {
                return false;
            }
        }
        return true;
    };
    int cur = 0;
    for (int i = 29; i >= 0; i--) {
        if (check(cur | (1LL << i))) cur |= (1LL << i);
        else ans |= (1LL << i);
    }
    cout << ans << '\n';
}
```