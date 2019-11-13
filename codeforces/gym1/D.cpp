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
ll n, k;
vector<vll> adj;
vll longest;
ll longestt(ll idx, ll parent) {
    ll mx = 1;
    for(auto it: adj[idx]) {
    	if(parent != it) {
            mx = max(mx, 1 + longestt(it, idx));
    	}
    }
    return longest[idx] = mx;
}
vll ans;
void dfs(ll idx, ll parent, ll sum) {
	bool foo = true;
	if(idx != 1 and adj[idx].size() == 1) ans.pb(sum);
	for(auto it: adj[idx]) {
		if(it == parent)continue;
		if(longest[it] + 1 == longest[idx] and foo) {
			dfs(it, idx, sum+1) ;
			foo = false;
		} else {
			dfs(it, idx, 1);
		}
	} 
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k;
  adj.resize(n+1);
  for(ll i = 2; i <= n; i++) {
  	ll tp;
  	cin >> tp;
  	adj[tp].pb(i);
  	adj[i].pb(tp);
  }
  longest.resize(n+1, 0);
  longestt(1, -1); 
  dfs(1, -1, 1);
  sort(all(ans), greater<ll>());
  ll ct = 0;
  for(ll i = 0; i < k; i++)ct+= ans[i];
  cout << ct << endl;
  return 0;
} //good night.