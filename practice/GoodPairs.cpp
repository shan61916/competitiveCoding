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
const ll mxx = (1ll << 20);
const ll tot = 20;

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
   vector<ll> a(n);
   unordered_map<ll, ll> key;
   vll dp(mxx+1, 0);
   vll freq(mxx+1, 0);
   ll ans = 0;
   for(ll i = 0; i < n; i++) {
    cin >> a[i];
    dp[a[i]]++;
    freq[a[i]]++;
   }
   for(ll i = 0; i < tot; i++) {
    for(ll j = 0; j < mxx; j++){
      if(j&(1ll<<i)) {
        dp[j]+= dp[j^(1ll << i)];
      } 
    }
   }
   for(ll i = 0; i < n; i++) {
    ans+= dp[a[i]] - freq[a[i]];
   }
   for(ll i = 0; i < n; i++) {
    ans+= (freq[a[i]]*(freq[a[i]] - 1))/2;
    freq[a[i]] = 0;
   }
   cout << ans << endl;
  }
  return 0;
} //good night.