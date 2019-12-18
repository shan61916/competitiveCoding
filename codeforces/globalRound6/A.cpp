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
   ll tot = 0;
   ll foo = 0;
   bool f = false;
   for(auto it: s) {
    tot+= it- '0';
    ll xx = it-'0';
    if(xx %2 == 0) foo++;
    if(xx == 0) f = true;
   }
   if(tot%3 == 0 and foo > 1 and f) cout << "red";
   else cout << "cyan";
   cout << endl;
  }
  return 0;
} //good night.