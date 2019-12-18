  //shan61916
#include <bits/stdc++.h>
  using namespace std;
// typedef   long long ll;
typedef   unsigned long long ll ;
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
   ll lcm = 1;
   ll l, r;
   cin >> l >> r;
   for(ll i = 0; i < n; i++) {
     lcm = ((lcm) / (__gcd(lcm, a[i]))) * a[i];
     if(lcm > r) lcm = 0;
   } 
   if(lcm == 0) {
    cout << (r - l + 1) << endl;
    continue;
   }
   ll ans = (r/lcm) - (((l-1))/lcm);
   cout << (r - l + 1) - ans << endl;
   }
  return 0;
} //good night.