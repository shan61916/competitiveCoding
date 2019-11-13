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
const ll mx = (ll)(1e6 + 10);
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   ll n;
   cin >> n;
   vll dp(mx, 0);
   vll arr(n);
   for(ll i = 0; i < n; i++) {
    ll tp;
    cin >> tp;
    dp[tp]++;
    arr[i] = tp;
   }
   for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++) {
      if(j&(1ll<<i)) {
        dp[j]+= dp[j^(1ll<<i)];
      }
    }
   }
   ll ans = 0;
   for(ll i = 0; i < mx; i++) {
     ll num = 0;
     for(ll j = 0; j <= 10; j++) {
       if(i&(1ll<<j)) continue;
       num+= (1ll<<j);
     }
     ans+= dp[num];
   }
   cout << ans << endl;
  }
  return 0;
} //good night.