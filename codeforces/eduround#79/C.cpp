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
   ll n, m;
   cin >> n >> m;
   vll a(n), b(n);
   map<ll, ll> key;
   for(ll i = 0; i < n; i++) cin >> a[i];
   for(ll i = 0; i < m; i++) cin >> b[i]; 
   for(ll i = 0; i < n; i++) key[a[i]] = i;
   ll ans = 0;
   ll mx = -1; 
   ll rem = 0;
   for(ll i = 0; i < m; i++) {
    if(key[b[i]] < mx) {
      ans+=1;
    } else {
      ans+= (2*(key[b[i]] - rem) + 1);
      mx = max(mx, key[b[i]]);
    }
    rem++;
   }
   cout << ans << endl;
  }
  return 0;
} //good night.