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
pair<pii, ll> a[1000005];
ll dp[1000005];
vector<pll> hull;

double getX(pll p1, pll p2) {
	return (p1.S - p2.S) * 1.0 / (p2.F - p1.F);
}

int ptr;
ll get(int x) {
	ptr = min(ptr, sz(hull) - 1);
	while (ptr + 1 < sz(hull) && hull[ptr + 1].F * x + hull[ptr + 1].S >= hull[ptr].F * x + hull[ptr].S)
		++ptr;
	return hull[ptr].F * x + hull[ptr].S;
}

void add(int i) {
	pll nwLine = {-1 * a[i].F.F, dp[i]};
	while (sz(hull) > 1 && getX(hull[sz(hull) - 2], nwLine) <= getX(hull[sz(hull) - 1], nwLine))
		hull.pop_back();
	hull.push_back(nwLine);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    	scanf("%d%d%lld", &a[i].F.F, &a[i].F.S, &a[i].S);
    sort(a, a + n);
    dp[0] = a[0].F.F * 1LL * a[0].F.S - a[0].S;
    hull.push_back({-1 * a[0].F.F, dp[0]});
    ll ans = dp[0];
    for (int i = 1; i < n; ++i) {
    	dp[i] = a[i].F.F * 1LL * a[i].F.S - a[i].S + get(a[i].F.S);
    	dp[i] = max(dp[i], a[i].F.F * 1LL * a[i].F.S - a[i].S);
    	add(i);
    	ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
