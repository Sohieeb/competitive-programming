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

int n, a[100005], b[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i),
        b[i] = a[i];
    sort(a, a + n);
    sort(b, b + n);
    int out = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && b[j] <= a[i]) ++j;
        if (j < n) ++out, ++j;
    }
    cout << out << endl;
    return 0;
}
