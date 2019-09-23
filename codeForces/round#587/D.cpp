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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  ll mx = 0; 
  sort(all(a));
  vll diff;
  for(ll i = 1; i < n; i++) {
  	diff.pb(a[i] - a[i-1]);
  } 
  diff.pb(0); 
  for(ll i = 0; i < (ll)diff.size(); i++) mx = __gcd(mx, diff[i]);
  ll mxx = a[n-1] ;  
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
  	ans+= (mxx - a[i])/mx;
  }
  cout << ans << " " << mx << endl;
  return 0;
} //good night.