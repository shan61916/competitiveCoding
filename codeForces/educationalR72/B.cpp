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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   ll n , x;
   cin >> n >> x;
   ll mx = INT_MIN, ar = 0;
   for(ll i = 0; i < n; i++) {
    ll d, h;
    cin >> d >> h;
    if((d - h) > mx) mx = (d - h) ;

    ar = max(d, ar);
   }
    if(ar >= x) {
    cout << 1 ;
   } else if(mx <= 0) {
    cout << -1;
   } else {
    ll tt = (x - ar) / mx ;
    if((x-ar)%mx)tt++;
    tt++;
    cout << tt ;
   }
    cout << endl;
  }
  return 0;
} //good night.