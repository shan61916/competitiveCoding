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
   string s, h;
   cin >> s >> h;
   ll n1 = s.length();
   sort(all(s));
   ll n2 = h.length();
   bool foo = false;
   for(ll i = 0; i < n2; i++) {
    string gv = "";
    if(i + n1 <= n2)gv = h.substr(i, n1);
    sort(all(gv));
    if(s == gv) foo = true;
   }
   if(foo) cout << "YES";
   else cout << "NO";
   cout << endl;
  }
  return 0;
} //good night.