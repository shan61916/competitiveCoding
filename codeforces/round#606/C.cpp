
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
   string s;
   cin >> s;
   vll res;
   ll n = s.length();
   for(ll i = 0; i < n; i++) {
    if(i + 4 < n) {
      string pp = "";
      for(ll ii = i; ii <= i + 4; ii++) pp.pb(s[ii]);
      if(pp == "twone") {
        s[i+2] = 'x';
        res.pb(i+3);
        continue;
      }
    }
    if(i + 2 < n) {
      if(s[i] == 'o' and s[i+1] == 'n' and s[i+2] == 'e') {
        s[i+1] = 'x';
        res.pb(i+2);
      } else if(s[i] == 't' and s[i+1] == 'w' and s[i+2] == 'o') {
        res.pb(i+2);
       }
    }
   }
   cout << res.size() << endl;
   for(auto it: res) {
    cout << it<< " " ;
   }
    cout << endl;
  }
  return 0;
} //good night.