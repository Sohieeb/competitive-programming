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

int n, m, p;
int a[1010];
int b[2020];

ll dp[1010][2020];

ll solve(int i, int j) {
    if (i == n) return 0;
    if (j == m) return LL_INF;
    ll &ret = dp[i][j];
    if (~ret) return ret;
    ret = solve(i, j + 1);
    ll mx = max(solve(i + 1, j + 1), 1LL * abs(a[i] - b[j]) + abs(b[j] - p));
    ret = min(ret, mx);
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(0, 0));
    return 0;
}
