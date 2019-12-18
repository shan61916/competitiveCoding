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
     ll a, b, c;
     cin >> a >> b >> c;
     ll ans = inf;
     ll dx[] = {a, a-1, a+1};
     ll dy[] = {b, b-1, b+1};
     ll dz[] = {c, c-1, c+1};
     for(ll i = 0; i < 3; i++) {
      for(ll j = 0; j < 3; j++) {
        for(ll k = 0; k < 3; k++) {
          ans = min(ans, abs(dx[i] - dy[j]) + abs(dy[j] - dz[k]) + abs(dz[k] - dx[i]));
        }
      }
     }
     cout << ans << endl;
  }
  return 0;
} //good night.