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

ll dp[1001][1001][11]	;
ll n ,m;
ll recurse(ll p1, ll p2, ll idx) {
	if(p1 > n) return 0;
	if(p2 < 1) return 0;
	if(p1 > p2) return 0;
	if(idx > m) return 1;
	ll &ans = dp[p1][p2][idx];
	if(ans != -1) return ans;
	ans = 0;
  ans = modadd(ans, recurse(p1, p2, idx+1));
  ans = modadd(ans, recurse(p1 + 1, p2, idx+1));
  ans = modadd(ans, recurse(p1, p2-1, idx+1));
	return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  ll ans = recurse(1, n, 1);
  cout << ans << endl;
  return 0;
} //good night.