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
   ll n, d;
   cin >> n >> d;
   vll a(n);
   for(auto &it: a) cin >> it;
   if(n == 1) {
   	cout << a[0] << endl;
   	continue;
   }
   ll ans = a[0];
   ll rem = d;
   for(ll i = 1; i < n; i++) {
   	ll can = min(a[i], rem/i);
   	rem-=can*i;
   	ans+= can;
   }
   cout << ans << endl;
  }
  return 0;
} //good night.