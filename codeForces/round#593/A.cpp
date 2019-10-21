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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    ll x, y, z;
    cin >> x >> y >> z;
    ll zz = z/2;
    ll ans = 0;
    ans+= 3 * min(zz, y);
    y-= min(zz, y);
    zz = y/2;
    ans+= 3 * min(zz, x);
    cout << ans << endl;
  }
  return 0;
} //good night.