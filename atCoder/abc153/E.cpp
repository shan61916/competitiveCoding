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
ll n;
ll tot = 0;
ll last = -1;
ll mx = 0;
void dfs(ll idx, ll mask, ll parent, ll level){
 tot++;
 if(level > mx) {mx = level; last = idx;}
 for(auto it: adj[idx]) {
 	if(it == parent) continue;
 	if(((1ll<<it)&mask) == 0) continue;
 	dfs(it, mask, idx, level+1);
 }
}

int main(){
  cin >> n;
  ll to = ((1ll << n));
  adj.resize(n);
  for(ll i = 0; i < n-1; i++) {
  	ll x, y;
  	cin >> x >> y;
  	--x;
  	--y;
  	adj[x].pb(y);
  	adj[y].pb(x);
  }
  unordered_map<ll, ll> key;
  for(ll i = 0; i < to; i++) {
  	ll start = -1;
  	for(ll j = 0; j < n; j++) {
  		if((1ll<<j)&(i)) {
  			start = j;
  			break;
  		}
  	}
  		if(start == -1) continue;
  		tot = 0, last = -1, mx = 0;
  		dfs(start, i, -1, 0);
  		if(tot == __builtin_popcountll(i)) {
  			mx = 0;
  			dfs(last, i, -1, 0);
  			key[mx]++;
  		}
  }
  for(ll i = 1; i <= n-1; i++) {
  	cout << key[i] << endl;
  }

  return 0;
} //good night.