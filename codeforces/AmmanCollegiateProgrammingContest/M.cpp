//shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;
 
#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 
ll n ; 
map<pair<ll, ll>, bool> isdir;
vector< vll > up;
vll s1, s2;
vll tin, tout ;
ll timer, l;
vector<vector<pair<ll, pll>>> badj;
void dfs(ll idx, ll parent) {
  tin[idx] = ++timer;
  up[idx][0] = parent;
  for(ll i = 1; i <= l; i++) {
    up[idx][i] = up[up[idx][i-1]][i-1];
  }
  for(auto it: badj[idx]) {
    if(it.ff == parent) continue;
    dfs(it.ff, idx);
  }
  tout[idx] = ++timer;
}
 
bool isancestor(ll u, ll v) {
  return (tin[u] <= tin[v] and tout[u] >= tout[v]);
}
 
ll lca(ll x, ll y) {
  if(isancestor(x, y)) return x;
  if(isancestor(y, x)) return y; 
 
  for(ll i = l; i >= 0; i--) {
    if(!isancestor(up[x][i], y)) {
      x = up[x][i];
    }
  }
   return up[x][0];
}
void c1(ll idx, ll parent) {
  for(auto it: badj[idx]) {
    if(it.ff == parent) continue;
    if(isdir[mp(idx, it.ff)] == true) {
      s1[it.ff] = it.ss.ff + s1[idx];
      s2[it.ff] = it.ss.ss + s2[idx];
    } else {
      s1[it.ff] = it.ss.ss + s1[idx];
      s2[it.ff] = it.ss.ff + s2[idx];
    }
    c1(it.ff, idx);
  }
} 
 
void preprocess() {
  s1.clear();
  s2.clear();
  tin.clear();
  tout.clear();
  up.clear();
  s1.resize(n, 0);
  s2.resize(n, 0);
  timer = 0;
  tin.resize(n, 0);
  tout.resize(n, 0);
  l = (ll)(ceil)(log2(n));
  up.resize(n, vll(l+1, 0)) ;
  dfs(0, 0);
}
 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    cin >> n;
    badj.resize(n);
    isdir.clear();
    ll tot = 0; 
    for(ll i = 1; i <= n-1; i++) {
      ll x, y, z, w;
      cin >> x >> y >> z >> w;
      tot+=z + w;
      x-=1, y-=1;
      isdir[mp(x, y)] = true;
      badj[x].pb(mp(y, mp(z, w)));
      badj[y].pb(mp(x, mp(z, w)));
    }
    preprocess();
    c1(0, 0);
    ll q;
    cin >> q;
    while(q--) {
      ll x, y;
      cin >> x >> y;
      x-=1, y-=1;
      ll lc = lca(x, y);
      ll tot1 = 0, tot2 = 0;
      if(x != lc) {
        tot1 = s1[x] - s1[lc];
      }
      if(y != lc) {
        tot2 = s2[y] - s2[lc];
      }
      cout << tot - tot1 - tot2 << endl;
    }
  }
 
  return 0;
} //good night.