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

int n, arr[100005];
pair<int, int> maxs[100005];
int secMx[100005];
int good;

int main() {
	scanf("%d", &n);
	pair<int, int> mx;
  	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		mx.F = max(mx.F, arr[i]);
		if (mx.F > mx.S) swap(mx.F, mx.S);
		maxs[i] = mx;
		if (maxs[i].S == arr[i]) good++;
		if (maxs[i].F == arr[i]) secMx[maxs[i].S]++;
	}
	int ans = 1, ansRec = 0;
	for (int i = 0; i < n; ++i) {
		if (maxs[i].F == arr[i]) --secMx[maxs[i].S];
		int me = good - (arr[i] == maxs[i].S) + secMx[arr[i]];
		if (me > ansRec) ans = arr[i], ansRec = me;
		else if (me == ansRec && arr[i] < ans) ans = arr[i], ansRec = me;
	}
	cout << ans << endl;
  	return 0;
}