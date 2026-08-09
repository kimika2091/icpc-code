## 1001

签到题。令 $A_i=a_i+x$，$B_i=b_i+y$，再令 $A_{n+1}=x$，$B_{m+1}=y$ 表示不选。最终乘积最大值在 $A_{min}B_{min}$，$A_{min}B_{max}$，$A_{max}B_{min}$，$A_{max}B_{max}$ 中产生。

## 1006

拆开计算每一盏灯的贡献。最终得分期望 $E=\sum_{i=1}^n a_iE(c_i)$，其中 $E(c_i)$ 表示点亮第 $i$ 盏灯后连续段的个数。

若记 $I_j$ 表示第 $j$ 盏灯亮且第 $j-1$ 盏灯不亮的概率，那么 $E(c_i)=\sum_{j=1}^nI_j$。

下面进行分类讨论：

- $1<i<n$时，容易得到 $I_1=\frac{1}{2}$，$I_i=\frac{1}{2}$，$I_{i+1}=0$。对于其他的 $j$，要满足点亮第 $i$ 盏灯后第 $j$ 盏灯亮且第 $j-1$ 盏灯不亮，所以这三盏灯的点亮顺序必须为 $j$，$i$，$j-1$，概率为 $\frac{1}{3!}=\frac{1}{6}$。因此 $E(c_i)=\frac{1}{2}+\frac{1}{2}+0+\frac{1}{6}(n-3)=\frac{n+3}{6}$。
- $i=1$ 时，同理可求得 $E(c_1)=1+0+\frac{1}{6}(n-2)=\frac{n+4}{6}$。
- $i=n$ 时，同理可求得 $E(c_n)=\frac{1}{2}+\frac{1}{6}(n-2)+\frac{1}{2}=\frac{n+4}{6}$。

综上，$E=\frac{n+4}{6}a_1+\frac{n+4}{6}a_n+\frac{n+3}{6}\sum_{i=2}^{n-1}a_i$，整理后得到 $E=\frac{a_1+a_n+(n+3)\sum_{i=1}^n a_i}{6}$。

## 1010

两个人从两端不断向中间推进，最后只剩 1 堆时游戏结束，可以发现我们需要比较的是前缀和与后缀和，且更靠近中心位置前（后）缀和更大的一方占优，只需要一直采用镜像策略就能够取胜。

我们取中心位置 $k=\lfloor\frac{n}{2}\rfloor$，记 $P_i =\sum_{j=1}^i{x_j}\,(1\le i\le k)$，$Q_i=\sum_{j=1}^{i}x_{n-j+1}\,(1\le i\le k)$。

当 $n$ 为奇数时，若字典序 $(P_k,\dots,P_1)>(Q_k,\dots,Q_{1})$，那么先手必胜。

当 $n$ 为偶数时，先手可以主动清空左端点转换为奇数情况，即若字典序 $(P_k,\dots,P_1)\ge(Q_{k-1},\dots,Q_{1})$，则先手必胜。

## 1004

问题转换如下：给定一棵以 1 为根的树。可以将树上两个连通块合并当且仅当它们之间有直接的边相连，操作代价为 $\sum a_i \times \sum b_i$。求将整棵树合并成一个大连通块的最小代价。

考虑从上到下的一条链 $x-y-z$。有两种合并顺序。

- 先合并 $x,y$ 再合并 $z$：代价为 $x_by_a+(x_b+y_b)z_a$
- 先合并 $y,z$ 再合并 $x$：代价为 $y_bz_a+x_b(y_a+z_a)$

两种方式的代价之差为 0，所以对于一条链，合并顺序并不影响最终代价。

考虑结构 $y-x-z$。其中 $y$ 和 $z$ 是连在 $x$ 上的两个孩子。有两种合并顺序。

- 先合并 $x,y$ 再合并 $z$：代价为 $x_by_a+(x_b+y_b)z_a$
- 先合并 $x,z$ 再合并 $y$：代价为 $x_bz_a+(x_b+z_b)y_a$

两种方式的代价之差为 $w=y_bz_a-z_by_a$。

令 $w<0$，可以推出 $\dfrac{y_b}{y_a}<\dfrac{z_b}{z_a}$。也就是说对于 $\dfrac{b}{a}$ 更小的节点我们需要优先合并。

可以准备一个堆，优先将 $\dfrac{b}{a}$ 值最小的节点合并到父节点。再利用并查集维护连通信息。有可能在堆中有尚未被更新的旧状态，跳过即可。时间复杂度约 $\mathcal{O}(n\log n)$。

```cpp
struct Node {
	int id;
	int a, b;
	double w() const { return 1.0 * b / a; }
	bool operator < (const Node &other) const {
		return w() > other.w();
	}
};

void solve() {
	int n;
	cin >> n;
	vector <Node> nodes(n + 1);
	for (int i = 1; i <= n; i++) nodes[i].id = i;
	for (int i = 1; i <= n; i++) cin >> nodes[i].a;
	for (int i = 1; i <= n; i++) cin >> nodes[i].b;
	vector <int> f(n + 1);
	vector <vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		if (f[i]) g[f[i]].push_back(i);
	}
	DSU dsu(n + 1);
	priority_queue <Node> q;
	for (int i = 1; i <= n; i++) {
		q.push(nodes[i]);
	}
	int ans = 0;
	vector <bool> vis(n + 1);
	while (!q.empty()) {
		auto [x, a, b] = q.top();
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		if (x == 1) continue;
		dsu.parent[x] = f[x];
		int ffx = dsu.find(f[x]);
		ans += nodes[x].a * nodes[ffx].b;
		nodes[ffx].a += nodes[x].a;
		nodes[ffx].b += nodes[x].b;
		q.push(nodes[ffx]);
	}
	cout << ans << '\n';
}
```





