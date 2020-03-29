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
  ll n, m;
  cin >> n >> m;
  vll a(n);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i];
  	a[i]/=2;
  }
  ll ans = 0;
  for(ll i = 1; i <= m; i++) {
  	ll tot = 0;
  	for(ll j = 0; j < n; j++) {
  		if(i%a[j]!= 0) break;
  		else {
  			ll rem = i/a[j];
  			if(rem%2) tot++;
  		}
  	}
  	if(tot == n) ans++;
  }
  cout << ans << endl;

  return 0;
} //good night.