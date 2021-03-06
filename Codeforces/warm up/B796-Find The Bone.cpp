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

int n, m, k;
int h[1000005], a, u, v, me;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m ,&k);
    for(int i = 0; i < m; ++i){
        scanf("%d", &a);
        h[a] = 1;
    }
    me = 1;
    if(h[me])
        return 0 * printf("%d\n", me);
    for(int i = 0; i < k; ++i){
        scanf("%d%d", &u, &v);
        if(u != me && v != me)
            continue;
        if(u == me)
            me = v;
        else
            me = u;
        if(h[me])
            return 0 * printf("%d\n", me);
    }
    printf("%d\n", me);
    return 0;
}