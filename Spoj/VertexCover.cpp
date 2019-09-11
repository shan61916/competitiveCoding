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
ll n;
vector<vll> adj;
vll parent;
ll dp[100010][3];
void dfs(ll x, ll y) {
	parent[x] = y;
	for(auto it: adj[x]) {
		if(it != y) {
			dfs(it, x);
		}
	}
}

ll recurse(ll idx, ll mode){
	ll &ans = dp[idx][mode];
	if(ans != -1) return ans;
	ans = 0;
	ll m1 = 0, m2 = 0; 
	for(auto it: adj[idx]) {
        	if(it != parent[idx]){
        		m1+= 1 + recurse(it, 1);
        	}
      }
	if(mode ==0) {
        ans = m1;
	} else if(mode == 1){
		for(auto it: adj[idx]){
			if(it!=parent[idx]) {
				m2+= min(recurse(it, 0), 1 + recurse(it, 1));
			}
		}
		ans = m2;
	}

	return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  adj.resize(n+1);
  for(ll i = 0; i < n-1; i++) {
  	ll x, y;
  	cin >> x >> y;
  	adj[x].push_back(y);
  	adj[y].push_back(x);
  }
  parent.resize(n+1, -1);
  dfs(1, -1) ; 
  memset(dp, -1, sizeof(dp));
  ll ans = min(recurse(1, 0), 1 + recurse(1, 1));
  cout << ans;
  return 0;
} //good night.