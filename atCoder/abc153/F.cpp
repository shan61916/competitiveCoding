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
  ll n, d, pow;
  cin >> n >> d >> pow;
  vector<pll> xx(n);
  for(ll i = 0; i < n; i++) cin >> xx[i].ff >> xx[i].ss;
  ll can = 2*d; 
  multiset<pll> st;
  multiset<pll> last;
  for(ll i = 0; i < n; i++) st.insert(xx[i]);
  ll curr = 0;
  ll ans = 0;
  while(!st.empty()) {
  	pll now = *st.begin();
  	ll at = now.ff;
  	if(!last.empty()) {
  		while(1) {
  			if(last.empty()) break;
  			pll gvv = *last.begin();
  			ll tt = gvv.ff;
  			if(at - tt <= can or last.empty()) break;
  			curr-= gvv.ss;
  			last.erase(last.begin());
  		}
  	}
   ll rem = now.second;
   rem = max(0LL, rem - curr);
   ll needed = ((rem + pow - 1))/pow;
   ans+= needed;
   curr+= needed*pow;
   st.erase(st.begin());
   last.insert(mp(at, needed*pow));
  } 
  cout << ans << endl;
  return 0;
} //good night.