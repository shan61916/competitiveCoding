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
const ll mxx = (ll) (1ll << 20ll);

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
   vll a(n);
   vll freq(mxx, 0);
   for(ll i = 0; i < n; i++) {
     cin >> a[i];
     freq[a[i]]++;
   }
   for(ll i = 0; i < 20; i++) {
     for(ll j = 0; j < mxx; j++) {
       if(j&(1ll<<i)) {
        freq[j]+= freq[j^(1ll<<i)];
       }
     }
   }
   ll ans = 0;
   ll larg  = mxx - 1;
   for(ll i = 0; i < n; i++) {
    ans+= freq[(a[i]^larg)];
   }
   cout << ans << endl;
  }
  return 0;
} //good night.