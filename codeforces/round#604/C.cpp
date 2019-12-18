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
  ll T;
  cin >> T;
  while(T--) {
   ll n;
   cin >> n;
   vll a(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   ll x = 0, y = 0, z = 0;
   vll diff;
   ll tot = n/2;
   for(ll i = 1; i < n; i++) {
     if(a[i] != a[i-1]) diff.pb(i);
   }
   diff.pb(n);
   ll sz = diff.size();
   ll mx = 0;
   for(ll i = 0; i < sz; i++) {
     ll g = diff[i];
     ll scan = g + g;
     auto it = upper_bound(all(diff), scan); 
     if(it == diff.end()) {
      continue;
     } 
     ll xx = *it;
     ll silv = xx - g;
     ll bronze = xx + tot - (silv + g);
     it = upper_bound(all(diff), bronze);
     ll pp = 0;
     if(it == diff.end()) {
       pp = diff[sz-1];
     } else {
       ll xex = it - (diff.begin());
       xex--;
       pp = diff[xex];
     }
     ll brz = 0;
     if(pp - xx > g) {
      brz = pp - xx;
     }
     if(brz + g + silv > mx and brz > 0 and g > 0 and silv > 0) {
      mx = brz + g + silv;
      x = g, y = silv, z = brz;
     }
   }
   cout << x << " " << y << " " << z << endl;
  }
  return 0;
} //good night.