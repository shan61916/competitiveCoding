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
const ll inf = (ll)(1e9);

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  vll dist(8, inf);
  dist[2] = 0;
  vector<pair<pll, ll>> arr;
  for(ll i = 0; i < 24; i++) {
  	ll x, y, z;
  	cin >> x >> y >> z;
    arr.pb(mp(mp(x, y), z));
  }
  	for(ll ii = 1; ii <= 7; ii++) {
  		if(dist[ii] >= 1000) cout <<"infinity " ;
  		else cout << dist[ii] << " ";
  	}
  	cout << endl;
  for(ll i = 1; i <= 6; i++) {
  	for(ll j = 0; j < 24; j++) {
  		ll x = arr[j].ff.ff;
  		ll y = arr[j].ff.ss;
  		ll z = arr[j].ss;
  		if(dist[x] < inf) {
  			dist[y] = min(dist[y], dist[x] + z);
  		}
  	}
  	for(ll ii = 1; ii <= 7; ii++) {
  		if(dist[ii] >= 1000) cout <<"infinity " ;
  		else cout << dist[ii] << " ";
  	}
  	cout << endl;
  }

  return 0;
} //good night.