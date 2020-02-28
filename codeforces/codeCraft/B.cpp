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
ll dp[100100][130];
ll n, p, k;
vector<vll> scores;
bool comp(vll &a, vll &b) {
	return a[7] >= b[7];
}
ll recurse(ll idx, ll mask) {
	ll tot = __builtin_popcountll(mask);
	ll others = idx - tot;
	if(idx >= n) {
		if(tot == p) return 0;
		return -inf;
	}
	ll &ans = dp[idx][mask];
	if(ans != -1) return ans;
	ans = 0;
	if(tot < p) {
		for(ll i = 0; i < p; i++) {
			if((mask&(1ll<<i))) continue;
		  ans = max(ans, scores[idx][i] + recurse(idx + 1, (mask|(1ll<<i))));
		}
	}
	if(others < k) {
		ans = max(ans, scores[idx][7] + recurse(idx + 1, mask));
	}
	ans = max(ans, recurse(idx + 1, mask));
	return ans; 
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> p >> k;
  scores.resize(n, vll(8, 0));
  for(ll i = 0; i < n; i++) cin >> scores[i][7];
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < p; j++) {
  		cin >> scores[i][j];
  	}
  }
  sort(all(scores), comp);
  memset(dp, -1, sizeof dp);
  ll ans = recurse(0, 0); 
  cout << ans << endl;
  return 0;
} //good night.