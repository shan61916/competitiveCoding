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
unordered_map<ll, ll> parent;
unordered_map<ll, ll> sz;
ll findset(ll x) {
	if(parent[x] == x) return x;
	return parent[x] = findset(parent[x]);
}

void unionset(ll x, ll y) {
	x = findset(x);
	y = findset(y);
	if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x]+= sz[y];
}


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m;
  cin >> n >> m;
  if(n == 1) {
  	for(ll i = 0; i < m; i++) cout << 0 << " ";
  	return 0;
  }
  vector<pair<ll, pll>> edges(n-1);
  for(ll i = 0; i < n-1; i++) {
  	cin >> edges[i].ss.ff >> edges[i].ss.ss >> edges[i].ff;
  }
  sort(all(edges));
  vector<pll> query(m);
  for(ll i = 0; i < m; i++) {
  	query[i].ss = i;
  	cin >> query[i].ff;
  } 
  for(ll i = 1; i <= n; i++){
   sz[i] = 1;
   parent[i] = i;
 }
  sort(all(query));
  unordered_map<ll, ll> ans;
  ll currans = 0;
  ll idx = 0;
  ll last = -1;
  for(auto it: query) {
  	if(last >= edges[idx].ff) {
  		ans[it.ss] = currans; 
  	} else {
  		while(idx < n-1 and edges[idx].ff <= it.ff) {
  			ll x = edges[idx].ss.ff, y = edges[idx].ss.ss;
  			x = findset(x), y = findset(y);
            currans-= (sz[x]*(sz[x]-1))/2,  currans-=(sz[y] * (sz[y]-1))/2;
            unionset(x, y);
            x = findset(x);
            // cout << x << endl;
            currans+= (sz[x] * (sz[x]-1))/2;
            last = edges[idx].ff;
            idx++;
  		}
        
  		ans[it.ss] = currans;
  	}
  }
  for(ll i = 0; i < m; i++) {
  	cout << ans[i] << " ";
  }
  return 0;
} //good night.