
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
const ll mod = (ll)(998244353);
ll mulmod(ll a, ll b) {
   return (a%mod * b%mod)%mod;
}
 
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res = mulmod(res, base);
       base= mulmod(base, base);
       exp/=2;
    }
    return res%mod;
}
 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vll a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  ll ans = 1;
  ll mx = a[n-1];
  map<ll, ll> key;
  for(auto it: a) key[it]++;
  if(key[0] != 1) {
    cout << 0 << endl;
    return 0;
  }
  for(ll i = 1; i <= mx; i++) {
    ans = mulmod(ans, fast_exp(key[i-1], key[i]));
  }
  cout << ans%mod;
  return 0;
} //good night.