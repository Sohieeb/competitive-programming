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

int n, m;
pair<pair<int,int>, int> arr[105];

bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
  return a.F.S < b.F.S;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n); sf(m);
  for(int i = 0; i < n; ++i)
    sf(arr[i].F.F), arr[i].F.S = i;
  sort(arr, arr + n);
  for(int i = 0; i < n; ++i)
    arr[i].S = i % 2;
  sort(arr, arr + n, cmp);
  for(int i = 0; i < n; ++i)
    printf("%d%c", arr[i].S, " \n"[i == n - 1]);
  return 0;
}