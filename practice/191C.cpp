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
ll n, k, timer, l; 
vector<vll> adj;
vll tin, tout;
vector<vll> up; 
vll val, ans;
map<pair<ll, ll>, ll> key;
void dfs(ll idx, ll p) {
	tin[idx] = ++timer;
	up[idx][0] = p;
	for(int i = 1; i <= l; i++) {
		up[idx][i] = up[up[idx][i-1]][i-1];
	}
	for(auto it: adj[idx]) {
		if(it == p) continue;
		dfs(it, idx);
	}
	tout[idx] = ++timer;
}
bool isancestor(ll x, ll y) {
	return (tin[x] <= tin[y] and tout[x] >= tout[y]);
}
ll lca(ll x, ll y) {
	if(isancestor(x, y)) return x;
	if(isancestor(y, x)) return y;
	for(ll i = l; i >= 0; i--) {
		if(!isancestor(up[x][i], y)) x = up[x][i];
	}
	return up[x][0];
}
void preprocess(ll root) {
	tin.resize(n+1);
	tout.resize(n+1);
	timer = 0;
	l = (ll)ceil((dll)(log2(n+1)));
	up.assign(n+1, vll(l+1));
	dfs(root, root);
	ans.resize(n, 0);
	val.resize(n+1, 0);
} 
void dfs1(ll idx, ll parent) {
	for(auto it: adj[idx]) {
		if(it == parent)continue;
		dfs1(it, idx);
		val[idx]+= val[it];
	}
	ll id = key[mp(min(idx, parent), max(idx, parent))];
    ans[id] = val[idx];
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  adj.resize(n+1);
  for(ll i = 1; i < n; i++) {
  	ll x, y;
  	cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
    key[mp(min(x, y), max(x, y))] = i;
  }
  preprocess(1);
  cin >> k;
  for(ll i = 1; i <= k; i++) {
  	ll x, y;
  	cin >> x >> y;
  	ll anc = lca(x, y);
  	val[x]+=1;
  	val[y]+=1;
  	val[anc]-=2;
  }
  dfs1(1, 1);
  for_each(ans.begin()+1, ans.end(), [](ll x){cout << x << " ";});
  return 0;
} //good night.