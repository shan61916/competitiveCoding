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
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++	 << ": "; 
  ll n, m;
  cin >> n >> m;
  vll a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  vll ct(61, 0); 
  for(ll i = 0; i <= 52; i++) {
  	for(ll j = 0; j < n; j++) {
  		if((a[j]&(1ll<<i)))ct[i]++;
  	}
  }
  vector<ll> did(64, 0);
  for(ll i = 0; i <= 52; i++) {
     ll ifset = (n - ct[i]) * (1ll<<i); 
     ll ifnot = ct[i]*(1ll<<i);
     if(ifset <= ifnot) {
     	ans+= ifset;
     	did[i] = 1;
     } else {
     	ans+= ifnot;
     	did[i] = 2;
     }
  }
  // cout << ans << endl;
  if(ans > m) {
  	cout << -1 << endl;
  	continue;
  }
  for(ll i = 52; i >= 0; i--) {
     ll ifset = (n - ct[i]) * (1ll<<i); 
     ll ifnot = ct[i]*(1ll<<i);
     if(did[i] == 1) continue;
     else if(did[i] == 2){
     	if(ans - ifnot + ifset <= m) {
     		did[i] = 1;	
     		ans = ans - ifnot + ifset;
     	}
     }  	
  }
   ll res = 0;
    for(ll i = 0; i <= 52; i++) {
    if(did[i] == 1) {
     	res|=(1ll<<i);
     }
   }
   cout << res << endl;
  }
  return 0;
} //good night.