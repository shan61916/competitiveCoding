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
const ll MOD  = (ll)(1e9+7);
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
ll mulmod(ll x, ll y) {
	return (x%MOD * y%MOD)%MOD;
}

ll modsub(ll x, ll y) {
	return (x%MOD - y%MOD + MOD)%MOD;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll x, y;
  cin >> x >> y;
  ll a = modsub(fast_exp(2, y), 1ll); 
  ll ans = fast_exp(a, x);
  cout << ans << endl;
  return 0;
} //good night.