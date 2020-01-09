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

vector<vll> adj;
vll out, in;
void dfs1(ll idx, ll parent, ll t) {
  ll ans = 0;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    dfs1(it, idx, t + 1);
    ans = max(ans, in[it]);
  }
  in[idx] = ans;
}

void dfs2(ll idx, ll parent) {
  ll mx1 = 0, mx2 = 0, id1 = 0;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    if(in[it] > mx1) {
      mx2 = mx1;
      mx1 = in[it];
      // id2 = id1;
      id1 = it;
    } else if(in[it] > mx2) {
      mx2 = in[it];
      // id2 = it;
    } 
  }
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    ll tocheck = 0;
    if(it == id1) tocheck = mx2;
    else tocheck = mx1;
    out[it] = max(out[idx], tocheck);
    dfs2(it, idx);
  }
}


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  adj.resize(n+1);
  in.resize(n+1, 0), out.resize(n+1, 0);
  for(ll i = 0; i < n-1; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs1(1, 1, 0);
  dfs2(1, 1);
  for(ll i = 1; i <= n; i++) {
    cout << in[i] << " " << out[i] << endl;
  }
  return 0;
} //good night.