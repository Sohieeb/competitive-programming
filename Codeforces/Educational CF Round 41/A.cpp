#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m, x;
int a[1010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    int res = 0;
    for(int i = 0; i < m; ++i){
        cin >> x;
        a[x]++;
        int cnt = 0;
        for(int j = 1; j <= n; ++j)
            if(a[j]) ++cnt;
        if(cnt < n) continue;
        ++res;
        for(int j = 1; j <= n; ++j)
            --a[j];
    }
    cout << res << endl;
    return 0;
}