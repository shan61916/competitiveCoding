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
   vector<pll> a(n);
   for(ll i = 0; i < n; i++) cin >> a[i].ff >> a[i].ss;
   ll tot = 0;
   string ans = "";
   sort(all(a));
   bool foo = true;
   pll prev = mp(0 , 0);
   for(ll i = 0; i < n; i++) {
   	 pll curr = a[i];
   	 if(curr.ff >= prev.ff) {
   	 	 ll xx = curr.ff - prev.ff;
   	 	 while(xx--) ans.pb('R');
   	 } else foo = false;

   	 if(curr.ss >= prev.ss) {
   	 	ll xx = curr.ss - prev.ss;
   	 	while(xx--) ans.pb('U');
   	 } else foo = false;
   	 if(foo) tot++;
   	 prev = a[i];
   }
   if(foo and tot >= n) {
   	cout << "YES" << endl;
   	cout << ans << endl;
   } else {
   	cout << "NO";
   	cout << endl;
   }
  }
  return 0;
} //good night.
