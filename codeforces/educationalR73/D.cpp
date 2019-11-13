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
vector<ll> a(300001), b(300000);
ll n;
const ll inf = (ll)(1e18);
ll dp[300001][4][4]; 
ll recurse(ll idx, ll did, ll third) {
	if(idx == n) {
		return 0;
	}
	ll &ans = dp[idx][did][third];
	if(ans != -1) return ans;
	ans = inf;
	ll x1 = inf, x2 = inf, x3 = inf;
	ll prev = a[idx-1]; 
	prev+=did;
	ll tt = inf;
	if(idx - 2 >= 0) {
       tt = a[idx-1] ;
       tt+=third;
	}
	// if(idx == 2) cout << did << " " << third << " " << prev << endl;
    ll p = inf;
    if(a[idx] == prev) {
    	x1 = b[idx] + recurse(idx+1, 1, did);
    	if(a[idx] != tt - 2) x2 = 2*b[idx] + recurse(idx+1, 2, did);
    	if(prev == tt - 1) {
            x3 = 2*b[idx-1] + recurse(idx+1, 0, did+2);
    	}  else {
    		x3 = b[idx-1] + recurse(idx+1, 0, idx+1);
    	}
    }
    else return ans = recurse(idx+1, 0, did);
    return ans = min(x1, min(x2, x3));
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> a[i] >> b[i];
  for(ll i = 0; i < n; i++) {
  	dp[i][1][0] = -1;
  	dp[i][1][1] = -1;
  	dp[i][0][1] = -1;
  	dp[i][0][0] = -1;
  }
  ll ans = min(b[0] + recurse(1, 1, 0), recurse(1, 0, 0)) ;

  cout << ans << endl;
  }
  return 0;
} //good night.