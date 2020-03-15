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
const ll mod = (ll)(998244353);
ll fast_exp(ll base, ll exp) {
  ll res=1;
  while(exp>0) {
    if(exp%2==1) res=(res*base)%mod;
      base=(base*base)%mod;
      exp/=2;
  }
  return res%mod;
}

ll modadd(ll x, ll y){return (x%mod + y%mod)%mod;}
ll modmul(ll x, ll y){return (x%mod * y%mod)%mod;}
ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
ll moddiv(ll x, ll y){return modmul(x, fast_exp(y, mod-2));}

vector<vll> next;
vll a;
ll n, s;
ll dp[3001][3001][2];
ll recurse(ll idx, ll sum, ll mode) {
	if(idx == n and sum == s) return 1;
	if(idx >= n or sum > s) return 0;
	ll &ans = dp[idx][sum][mode];
	if(ans != -1) return ans;
	ans = 0;
	ll toadd = (sum == s);
	if(mode == 1)ans = modadd(ans, toadd + recurse(idx + 1, sum, 1));
	ans = modadd(ans, toadd + recurse(idx + 1,  sum + a[idx], 1));
	return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> s;
  a.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
  	ll tot = recurse(i, 0, 0);
  	cout << tot << endl;
  	ans = modadd(ans, tot);
  }
  // cout << ans << endl;
  return 0;
} //good night.