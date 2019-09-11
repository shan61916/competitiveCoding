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
ll a, b, c, d;
ll lcm(ll aa, ll bb) {
	return (aa*bb)/__gcd(aa, bb) ;
}

ll can(ll x) {
    ll tot = (x/a) + (x/b) + (x/c) + (x/lcm(a, b)) + (x/lcm(b, c)) + (x/lcm(a, c)) - (x /lcm(a, lcm(b, c)));
    return tot;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   cin >> a >> b >> c >> d;
   ll low = 1, high = (ll)(1e18), ans = 0, mid = 0;
   while(low <= high) {
   	mid = (low + high)/2;
   	ll tt = can(mid);
   	if(tt < d) {
   		low = mid + 1;
   		ans = mid;
   	} else {
   		high = mid - 1;
   	}
   }
   cout << ans << endl;
  }
  return 0;
} //good night.