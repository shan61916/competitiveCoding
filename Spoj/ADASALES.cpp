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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);
ll n, q;
vector<vll> adj;
vll in, out, cost;
void dfs1(ll idx, ll parent){
  ll mxcost1 = 0;
  ll tt = 0;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    tt = 0;
    if(cost[it] - cost[idx] > 0) tt = cost[it] - cost[idx];
    dfs1(it, idx);
    tt+= in[it];
    if(tt > mxcost1) {
      mxcost1 = tt;
    }
  }
  in[idx] = mxcost1;
}

void dfs2(ll idx, ll parent) {
  ll mx1 = 0, mx2 = 0;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    ll touse = (cost[it] - cost[idx] > 0) ? cost[it] - cost[idx] : 0;  
    if(in[it] + touse > mx1) mx2 = mx1, mx1 = in[it] + touse;
    else mx2 = max(mx2, in[it] + touse);
  }
  ll gv;
  // if(idx == 3) cout << mx1 << " " << mx2 << endl;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    ll touse = mx1;
    gv = 0;
    if(cost[it] - cost[idx] > 0) gv = cost[it] - cost[idx];
    if(in[it] + gv == touse) touse = mx2;
    ll k = 0;
    if(cost[idx] - cost[it] > 0) k = cost[idx] - cost[it];
    out[it] = k + max(out[idx], touse);
    dfs2(it, idx);
  }
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> q;
  cost.resize(n);
  for(ll i = 0; i < n; i++) cin >> cost[i];
  adj.resize(n);
  for(ll i = 1; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  in.resize(n);
  out.resize(n);
  dfs1(0, 0);
  dfs2(0, 0);
  // cout << out[3] << endl;
  while(q--) { 
    ll p;
    cin >> p;
    cout << max(in[p], out[p]) << endl;
  }
  return 0;
} //good night.