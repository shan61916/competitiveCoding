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
  ll n;
  cin >> n;
  vll a(n + 1);
  for(ll i = 1; i <= n; i++) cin >> a[i];
  ll curr = 0;
  map<ll, ll> mp;
  set<ll> st;
  set<ll> mt;
  st.insert(n);
  mt.insert(-1);
  ll ans = (n*(n+1))/2;
  for(ll i = 1; i <= n; i++) {
  	mp[curr] = i;
  	curr+=a[i];
  	if(mp[curr]) {
  		ll from = mp[curr];
  		ll to = i;
  		ll xx = *st.lower_bound(to);
  		ll yy = *mt.lower_bound(-from);
  		// cout << from << endl;
  		// cout << xx << " " << yy << endl;
  		xx = abs(xx - from + 1);
  		yy = abs(yy - to + 1);
  		// cout << from << " " << to << endl;
  		// cout << xx << " " << yy << endl;
  		ans-= xx*yy;
  		st.insert(to);
  		mt.insert(-from);
  	}
  }
  cout << ans << endl; 
  return 0;
} //good night.