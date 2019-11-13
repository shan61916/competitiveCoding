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
  ll n, k;
  cin >> n >> k;
  vector<pll> a;
  for(ll i = 0; i < n; i++) {
  	ll tp;
  	cin >> tp;
  	ll x = 1;
  	a.pb(mp(0, tp));
  	tp/=2; 
  	while(1) {
  	   a.pb(mp(x, tp));
  	   if(tp == 0) break;
       tp/=2; 
       x++;
  	}
  }
  sort(all(a));
  ll ans =  INT_MAX;
  unordered_map<ll, ll> done, cost ; 
  for(ll i = 0; i < (ll)a.size(); i++) {
  	// cout << a[i].ss << " " << done[a[i].ss] << endl;
  	if(done[a[i].ss] == k ) {
  		ans = min(ans, cost[a[i].ss]);
  	}
  	else {
  		done[a[i].ss]++;
  		cost[a[i].ss]+= a[i].ff;
  	}
  }
  for(auto it: a) {
  	if(done[it.ss] == k) ans = min(ans , cost[it.ss]) ;
  }
  cout << ans << endl;
  return 0;
} //good night.