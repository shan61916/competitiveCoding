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
ll n, c, k;
string s;
ll dp[100010][10]; 
ll mod = 1;

ll modadd(ll x, ll y) {
	return (x%mod + y%mod)%mod;
}

ll recurse(ll idx, ll did) {
	if(idx == n) {
		ll curr = 0;
		for(ll i = did; i >= 1; i--) {
			curr*= 10;
			curr+= (ll)(s[n-i] -'0');	
		}
		if(curr <= c) return 1;
		return 0; 
	}
    ll &ans = dp[idx][did];
    if(ans != -1) return ans;
    ans = 0;
    ll curr = 0;
    for(ll i = did; i >= 1; i--) {
    	curr*= 10;
    	curr+= (ll)(s[idx-i] - '0');
    }

    if(curr > c) return ans;
    ll thiss = (curr * 10) + (ll)(s[idx]-'0');
    if(s[idx] != '0') ans = modadd(recurse(idx+1, 1), ans);
    if(thiss <= c and idx != 0) ans = modadd(recurse(idx+1, did+1), ans);

    return ans%mod;  
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif  
  cin >> n >> c >> k;
  cin >> s;
  mod = 1;
  for(ll i = 1; i <= k; i++) mod*= 10;
  // cout << mod << endl;
  memset(dp, -1, sizeof(dp));
  ll ans = recurse(0, 0) ;

  cout << ans << endl;
  return 0;
} //good night.