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
  ll T;
  cin >> T;
  while(T--) {
   ll n;
   cin >> n;
   map<ll, ll> key;
   set<ll, greater<ll>> st;
   set<ll> done;
   for(ll i = 1; i <= n; i++) {
    ll tp;
    cin >> tp;
    st.insert(tp);
    key[tp]++;
   }
   ll ans = 0;
   for(auto it: st) {
     if(done.find(it) != done.end() or it%2) continue;
     ll todo = 0;
     ll xx = it;
     while(xx%2 == 0 and (done.find(xx) == done.end())) {
      todo++;
      done.insert(xx);
      xx/=2;
     }
     ans+= todo;
   }
   cout << ans << endl;
  }
  return 0;
} //good night.