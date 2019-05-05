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

int n, h, m;
int a[55];

int main() {
    scanf("%d%d%d", &n, &h, &m);
    for (int i = 1; i <= n; ++i)
    	a[i] = h;
    for (int i = 0; i < m; ++i) {
    	int l, r, x;
    	scanf("%d%d%d", &l, &r, &x);
    	for (int j = l; j <= r; ++j)
    		a[j] = min(a[j], x);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
    	// cout << a[i] << " " ;
    	ans += a[i] * a[i];
    }
    cout << ans << endl;
    return 0;
}