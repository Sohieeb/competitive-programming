#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F          first
#define S          second
#define pnl        printf("\n")
#define sz(x)      (int)x.size()
#define sf(x)      scanf("%d",&x)
#define pf(x)      printf("%d\n",x)
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define rep(i, n)  for(int i = 0; i < n; ++i)

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

const int N = 300005;
int n, q;
vector<int> adj[N];
int hi[N];
int siz[N];
int order[N], lst;
int idxOf[N];

int dfs(int u, int h) {
    hi[u] = h;
    order[lst] = u;
    idxOf[u] = lst++;
    siz[u] = 1;
    for (auto v : adj[u])
        siz[u] += dfs(v, h + 1);
    return siz[u];
}

int seg[2][4*N], lazy[2][4*N];

void upd(int op, int id, int l, int r, int x) {
    lazy[op][id] += x;
    if (lazy[op][id] >= mod) lazy[op][id] -= mod;
    seg[op][id] += (x * 1LL * (r - l)) % mod;
    if (seg[op][id] >= mod) seg[op][id] -= mod;
}

void shift(int op, int id, int l, int r) {
    int mid = (l + r) / 2;
    upd(op, id * 2, l, mid, lazy[op][id]);
    upd(op, id * 2 + 1, mid, r, lazy[op][id]);
    lazy[op][id] = 0;
}

void update(int op, int x, int y, int v, int id = 1, int l = 0, int r = n) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
        upd(op, id, l, r, v);
        return;
    }
    shift(op, id, l, r);
    int mid = (l + r) / 2;
    update(op, x, y, v, id * 2, l, mid);
    update(op, x, y, v, id * 2 + 1, mid, r);
    seg[op][id] = seg[op][id * 2] + seg[op][id * 2 + 1];
    if (seg[op][id] >= mod) seg[op][id] -= mod;
}

int query(int op, int x, int y, int id = 1, int l = 0, int r = n) {
    if (x >= r || l >= y) return 0;
    if (x <= l && r <= y) return seg[op][id];
    shift(op, id, l, r);
    int mid = (l + r) / 2;
    int ans = query(op, x, y, id * 2, l, mid) 
            + query(op, x, y, id * 2 + 1, mid, r);
    if (ans >= mod) ans -= mod;
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 2, v; i <= n; ++i) {
        scanf("%d", &v);
        adj[v].push_back(i);
    }
    dfs(1, 1);
    scanf("%d", &q);
    for (int i = 0, type; i < q; ++i) {
        scanf("%d", &type);
        if (type == 1) {
            int v, x, k;
            scanf("%d%d%d", &v, &x, &k);
            int val1 = (x + hi[v] * 1LL * k) % mod;
            update(0, idxOf[v], idxOf[v] + siz[v], val1);
            update(1, idxOf[v], idxOf[v] + siz[v], k);
        } else {
            int v;
            scanf("%d", &v);
            int ans1 = query(0, idxOf[v], idxOf[v] + 1);
            int ans2 = query(1, idxOf[v], idxOf[v] + 1);
            ans2 = (ans2 * 1LL * hi[v]) % mod;
            ans1 -= ans2;
            if (ans1 < 0) ans1 += mod;
            printf("%d\n", ans1);
        }
    }
    return 0;
}
