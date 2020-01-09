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
   ll n, s;
   cin >> n >> s;
   vll a(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   vll b(n);
   b[0] = a[0];
   for(ll i = 1; i < n; i++) b[i] = a[i] + b[i-1];
   ll ans = 0, mx = -1;
   for(ll i = 0; i < n; i++) {
    ll curr = b[i]; 
    ll hv = i;
    curr-= a[i];
    if(hv + 1> mx and b[i] <= s) {
      mx = hv + 1;
      ans = 0;
    } 
    if(s-curr > 0){
     ll idx = upper_bound(all(b), b[i] + (s - curr)) - b.begin();
     hv = i + (idx - i - 1); 
     if(hv > mx) {
     mx = hv;
     ans = i+1;
    }
    }
   }
   cout << ans << endl;;
  }
  return 0;
} //good night.