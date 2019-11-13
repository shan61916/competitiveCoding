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
vll arr;
vector<vll> adj;
ll n;
dll tot;
void dfs(ll idx, ll parent, ll len, dll prob) {
	ll ct = 0;
	for(auto it : adj[idx]) {
		if(it == parent) continue;
		ct++;
		
	}
	dll newprob = (dll)(prob)*((dll)(1.00)/(dll)(ct)); 
	for(auto it : adj[idx]) {
		if(it == parent) continue;
		dfs(it, idx, len+1, newprob);

	}
	if(adj[idx].size() == 1 and idx != 1) {
		tot+= (dll)((dll)(len)*(dll)(prob));
	}
}


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  adj.clear();
  adj.resize(n+1);
  for(ll i = 1; i < n; i++) {
  	ll x,y;
  	cin >> x >> y;
  	adj[x].pb(y);
  	adj[y].pb(x);
  }
  arr.clear();
  if(n == 1) {
  	cout << "0.0000" << endl;
  	return 0;
  }
  tot = 0.00;
  dfs(1, 1, 0, 1.00);
  cout << fixed << setprecision(7) << tot << endl;
  return 0;
} //good night.