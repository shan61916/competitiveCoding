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
   ll x;
   cin >> x;
   bool foo = false;
   ll dx[] = {20, 15, 17, 18, 16, 19};
   for(ll i = 0; i < 6; i++) {
    ll p = x - dx[i];
    if(p >= 0 and p%14 == 0) foo = true;
   }
   foo ? cout << "YES" : cout << "NO";
   cout << endl;
  }
  return 0;
} //good night.