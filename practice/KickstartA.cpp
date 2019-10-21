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
  map<vector<ll>, ll> key;
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++ << ": "; 
  ll n, s;
  cin >> n >> s;
  vector<vll> a(n);
  vll sz(n);
  ll x;
  ll tp;
  key.clear();
  for(ll i = 0; i < n; i++) {
  	cin >> x;
  	sz[i] = x;
  	while(x--) {
      cin >> tp;
      a[i].pb(tp);
  	}
  	sort(all(a[i]));
  	key[a[i]]++;
  }
  vll aux;
  ll ans = 0, tt = 0, tot = 0;
  for(ll i = 0; i < n; i++) {
  	tt = sz[i];
  	tot = 0;
  	for(ll j = 0; j < (1ll<<tt); j++) {
  		aux.clear();
  		for(ll k = 0; k < tt; k++) {
            if(j&(1<<k)) aux.pb(a[i][k]);
  		}
  		tot+=key[aux];
  	}
  	ans+= (n - tot);
  }
  cout << ans << endl;
  }
  return 0;
} //good night.