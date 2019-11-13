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
ll dp[100001]; 
ll n;
string s;
const ll mod = (ll)(1e9 + 7);
ll modadd(ll x, ll y) {
	return (x%mod + y%mod)%mod;
}
ll recurse(ll idx) {
	if(idx >= n-1) return 1;
	ll &ans = dp[idx];
	if(ans != -1) return ans;
	ans = 0;
	ans = modadd(ans, recurse(idx+1));
	if(s[idx] == 'u' and s[idx+1] == 'u') {
		ans = modadd(ans, recurse(idx+2));
	}
	if(s[idx] == 'n' and s[idx+1] == 'n') {
		ans = modadd(ans, recurse(idx+2));
	}
	return ans;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> s;
  n = s.length();
  memset(dp, -1, sizeof(dp));
  if(count(all(s), 'w') or count(all(s), 'm')) {
  	cout << 0;
  	return 0;
  }
  ll ans = recurse(0); 
  cout << ans << endl;
  return 0;
} //good night.