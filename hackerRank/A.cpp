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
  unordered_map<ll, ll> x; 
  unordered_map<ll, ll> y;
  map<pll, ll> xy;
  vector<pll> ae;
  ll n;
  cin >> n;
  for(ll i = 0; i < n; i++) {
  	ll a, b;
  	cin >> a >> b;
  	x[a]++;
  	y[b]++;
  	xy[mp(a, b)]++;
  	ae.pb(mp(a, b));
  }
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
    ll t = x[ae[i].ff] - 1;
    t+= y[ae[i].ss] - 1;
    t-= xy[ae[i]]-1;
    ans+=t;
  }
  ans/=2;
  cout << ans << endl;
  return 0;
} //good night.