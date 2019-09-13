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
vector<ll> subsize;
void dfs(ll idx, ll parent) {
	if(adj[idx].size() == 1 and idx != 1) {
		subsize[idx] = 1;
	}
	// cout << idx < " ";
	for(auto it: adj[idx]) {
		if(it != parent){
			dfs(it, idx);
			subsize[idx]+= subsize[it];
		}
	}
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  adj.resize(n+1);
  for(ll i = 2; i <= n; i++) {
  	ll x;
  	cin >> x;
  	adj[x].pb(i);
  	adj[i].pb(x);
  }
  subsize.resize(n+1, 0);
  dfs(1, -1);
  vector<ll> ans;
  for(ll i = 1; i <= n; i++) ans.pb(subsize[i]);
  ll mtill = 1;
  sort(all(ans));
  for(auto it: ans) {
     mtill = max(mtill, it);
     cout << mtill << " ";
  }
  cout << endl;
  return 0;
} //good night.