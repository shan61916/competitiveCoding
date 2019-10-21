  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef long long ll;
// typedef   unsigned long long ull ;
// typedef   double dll ;

#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    ll l, r;
    cin >> l >> r;
    ll ans = r;
    bool foo = false;
    for(ll i = 60; i >= 0; i--) {
       bool xx = (l&(1ll<<i));
       bool yy = (r&(1ll<<i));
    	 if(!foo and (xx != yy)) {
           ans|= (1ll<<i);
           foo = true;
       } else if(foo) {
         ans|= (1ll<<i);
       }
    }
    cout << ans << endl;
}
  return 0;
} //good night.
// 1000000123456
// 1099511627775
// 1000000000123