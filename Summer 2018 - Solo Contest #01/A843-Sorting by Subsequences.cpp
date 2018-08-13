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

int n;
int a[100005];
int b[100005];
vector<int> adj[100005];
int idxOf[100005];
int vis[100005];
vector<int> cur;

void dfs(int v) {
    vis[v] = 1;
    cur.push_back(idxOf[v]);
    for (auto u : adj[v])
        if (!vis[u])
            dfs(u);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    vector<int> com;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), com.push_back(a[i]);
    sort(all(com));
    for (int i = 1; i <= n; ++i) {
        b[i] = 1 + lower_bound(all(com), a[i]) - com.begin();
        idxOf[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        adj[i].push_back(b[i]);
    vector<vector<int> > ans;
    for(int i = 1; i <= n; ++i) {
        if (vis[i])
            continue;
        cur.clear();
        dfs(i);
        ans.push_back(cur);
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d", sz(ans[i]));
        for (int j = 0; j < sz(ans[i]); ++j)
            printf(" %d", ans[i][j]);
        printf("\n");
    }
    return 0;
}
