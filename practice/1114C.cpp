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
vector<ll> spf(5000010, 0) ;; 
const ll maxx = 5000010;
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, b;
  cin >> n >> b;
  vector<pll> pfs;
  ll ct = 0;
  while(b%2 == 0) {
     ct++;
     b/=2;
  } 
  if(ct) pfs.pb(mp(2, ct));
  for(ll i = 3; i*i <= b; i++) {
  	if(b%i == 0) {
  		ct = 0;
  		while(b%i == 0) {
  			b/=i;
  			ct++;
  		}
  		pfs.pb(mp(i, ct));
  	}
  }
  if(b > 2) pfs.pb(mp(b, 1));
  ll ans = (ll)(1e17 + 1e9);
  for(auto it : pfs) { 
  	ans = min(ans, n/it.ff/it.ss);
  }
  cout << ans << endl;
  return 0;
} //good night.