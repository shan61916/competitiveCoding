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

ll toget(ll a) {
  if(a == 3) return 100000;
  if(a == 2) return 200000;
  if(a == 1) return 300000;
  return 0;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll a, b;
  cin >> a >> b;
  ll ans= toget(a);
  ans+= toget(b);
  if(a == 1 and b == 1) {
    ans+= 400000;
  }
  cout << ans << endl;
  return 0;
} //good night.