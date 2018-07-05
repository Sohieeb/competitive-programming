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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n, q, c;
vector<int> me[105][105];
int com[12][105][105];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &q, &c);
    for(int i = 0; i < n; ++i){
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        me[x][y].push_back(s);
    }
    for(int k = 0; k <= c; ++k){
        for(int i = 0; i < 105; ++i)
            for(int j = 0; j < 105; ++j)
                for(auto v : me[i][j])
                    com[k][i][j] += (v + k) % (c + 1);
        for(int i = 0; i < 105; ++i)
            for(int j = 0; j < 105; ++j){
                if(i > 0) com[k][i][j] += com[k][i - 1][j];
                if(j > 0) com[k][i][j] += com[k][i][j - 1];
                if(i * j) com[k][i][j] -= com[k][i - 1][j - 1];
            }
    }
    while(q--){
        int t, x, y, xx, yy;
        scanf("%d%d%d%d%d", &t, &x, &y, &xx, &yy);
        t %= (c + 1);
        int res = com[t][xx][yy];
        res -= com[t][x - 1][yy];
        res -= com[t][xx][y - 1];
        res += com[t][x - 1][y - 1];
        printf("%d\n", res);
    }
    return 0;
}
