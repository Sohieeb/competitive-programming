/*
Author: Ibrahim Abdelrahman (aka.Sohieb)

Idea:

*/


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

int n, k;
char a[4][101];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    if(k <= n - 2){
        if(k % 2){
            --k;
            a[1][n / 2] = '#';
        }
        int i = n / 2 - 1, j = n / 2 + 1;
        while(k){
            a[1][i--] = a[1][j++] = '#';
            k -= 2;
        }
    } else {
        k -= (n - 2);
        for(int i = 1; i < n - 1; ++i)
            a[1][i] = '#';
        if(k % 2){
            --k;
            a[2][n / 2] = '#';
        }
        int i = n / 2 - 1, j = n / 2 + 1;
        while(k){
            a[2][i--] = a[2][j++] = '#';
            k -= 2;
        }
    }
    puts("YES");
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < n; ++j)
            printf("%c", a[i][j] == '#' ? '#' : '.');
        cout << endl;
    }
    return 0;
}
