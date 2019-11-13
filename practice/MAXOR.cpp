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
   vll arr(n);
   for(ll i = 0; i < n; i++) cin >> arr[i];
   vll freq(mx, 0);
   for(auto it: arr) freq[it]++;
   ll dp[mx];
   for(ll i = 0; i < mx; i++) {
      dp[i] = max(0LL, freq[i]-1);
   }
   for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < mx; j++) {
      if(j & (1ll << (arr[i]))) {
        dp[j]+= dp[j^(1ll << (arr[i]))];
      }
    }
   }
   ll ans = 0;
   for(ll i = 0; i < mx; i++) ans+= dp[i];
   cout << ans/2 << endl;
  }
  return 0;
} //good night.