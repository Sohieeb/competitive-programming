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

int n, x;
int a[1000005];
int L[1000005], R[1000005];
int mxs[1000005];

int main() {
    scanf("%d%d", &n, &x);
    memset(L, 0x3f, sizeof L);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d", &a[i]);
    	mxs[i] = max(mxs[i - 1], a[i]);
    	L[a[i]] = min(L[a[i]], i);
    	R[a[i]] = i;
    }
    int pre = 0, suf = 0, lst = 0;
    for (int i = 1; i <= x; ++i) {
    	if (R[i] == 0 && lst > 0) {
    		++pre;
    		continue;
    	}
    	if (L[i] < R[lst]) break;
    	++pre;
    	lst = i;
    }
    if (pre == x) {
    	cout << x * 1LL * (x + 1) / 2 << endl;
    	return 0;
    }
    lst = x + 1;
    for (int i = x; i >= 1; --i) {
    	// cout << i << " " << lst << endl;
    	if (L[i] == 0x3f3f3f3f && lst < x + 1) {
    		++suf;
    		continue;
    	}
    	if (R[i] > L[lst]) break;
    	++suf;
    	lst = i;
    	// cout << i << " " << lst << endl;
    }
    // cout << pre << " " << suf << endl;
    ll ans = 0;
    lst = 0;
    for (int i = 0; i < x; ++i) {
    	if (i > pre) break;
    	if (L[i] < 0x3f3f3f3f) lst = i;
    	int j = max(x - suf + 1, mxs[R[lst]] + 1);
    	// cout << i << " " << j << " " << (x - j + 2) << endl;
    	ans += (x - j + 2);
    }
    cout << ans << endl;
    return 0;
}
