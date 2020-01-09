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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll l, r;
  cin >> l >> r;
  ll ans = 0;
  for(ll i = l; i <= r; i++) {
    if(i%2) continue;
    if(i == 1) ans+=-1;
    if(i == 1) continue;
    for(ll j = 0; j <= 62; j++) {
      if(i&(1ll<<j)) {
        if((i&(i-1)) == 0)  {
         ans+= -1;
        } else ans+= (i^(1ll<<j));
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
} //good night.