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
vector<vll> adj;
ll given[100010][4];
ll arr[100010];
ll rem(ll x, ll y) {
  ll gv = 0;
  gv|=(1ll<<x);
  gv|=(1ll<<y);
  for(ll i = 1; i <= 3; i++) {
    if(((1ll<<i)&(gv)) == 0) return i;
  }
  return 0;
}
void make(ll idx, ll prev, ll toput, ll parent) {
  ll next = rem(prev, toput);
  arr[idx] = toput;
  for(auto it: adj[idx]) {
    if(it == parent)continue;
    make(it, toput, next, idx);
  }
}

ll dfs(ll idx, ll prev, ll toput, ll parent) {
  ll cost = given[idx][toput];
  ll next = rem(prev, toput);
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    cost+= dfs(it, toput, next, idx);
  }
  return cost;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  adj.resize(n+1);
  for(ll j = 1; j <= 3; j++) {
  for(ll i = 1; i <= n; i++) {
    cin >> given[i][j];
  }
}
  for(ll i = 1; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  ll root;
  for(ll i = 1; i <= n; i++) {
     // cout << adj[i].size() << endl;
     if(adj[i].size() > 2) {
      cout << -1;
      return 0;
     }
     if(adj[i].size() == 1) {
      root = i;
     } 
  }

  ll ans = (ll)1e17;
  ll tp = dfs(root, 2, 1, -1);
  if(tp < ans) {
    ans = tp;
    make(root, 2, 1, -1);
  }
  tp = dfs(root, 3, 1, -1);
   if(tp < ans) {
    ans = tp;
    make(root, 3, 1, -1);
  }
  tp = dfs(root, 1, 2, -1);
   if(tp < ans) {
    ans = tp;
    make(root, 1, 2, -1);
  }  
  tp = dfs(root, 3, 2, -1);
   if(tp < ans) {
    ans = tp;
    make(root, 3, 2, -1);
  }  
   tp = dfs(root, 1, 3, -1);
   if(tp < ans) {
    ans = tp;
    make(root, 1, 3, -1);
  }  
  tp = dfs(root, 2, 3, -1);
   if(tp < ans) {
    ans = tp;
    make(root, 2, 3, -1);
  } 
  cout << ans << endl;
  for(ll i = 1; i <= n; i++) cout << arr[i] << " ";
  return 0;
} //good night.