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
   map<pll, ll> key;
   ll ans = inf;
   ll x = 0, y = 0;
   key[mp(0, 0)] = 0;
   ll tx = -1, ty = -1;
   ll n;
   cin >> n;
   string s;
   cin >> s;
   for(ll i = 0; i < n; i++) {
   	 if(s[i] == 'U') y++;
   	 if(s[i] == 'D') y--;
   	 if(s[i] == 'R') x++;
   	 if(s[i] == 'L') x--;
   	 if(key.find(mp(x, y)) != key.end()) {
   	 	 if((i) - key[mp(x, y)] < ans) {
   	 	 	ans = (i) - key[mp(x, y)];
   	 	 	tx = key[mp(x, y)]; ty = i ;
   	 	 }
   	 }
   	 key[mp(x, y)] = i + 1;
   }
   if(ans == inf) cout << -1 << endl;
   else cout << tx + 1 << " " << ty + 1 << endl;
  }
  return 0;
} //good night.
