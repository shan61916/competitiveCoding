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

const int MAX = 1e3 + 3;
const int MOD = 1e9 + 7;

ll val[7];
ll ncr(ll x, ll y) {
  ll ans = 1;
  ll rem = x - y;
  while(x > y) {
    ans*= x;
    x--;
  }
  while(rem > 0) {
    ans/= rem;
    rem--;
  }
  return ans;
}
void pascal() {
  val[1] = 0;
  val[2] = 1;
  for(ll i = 3; i < 7; i++) {
    val[i] = (i-1) * (val[i-1] + val[i-2]);
  }
} 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
    pascal();
    ll n, k;
    cin >> n >> k; 
    ll curr = (n-k);
    ll cc = k;
    ll ans = 1;
    while(curr < n) {
      ans+= ncr(n, curr) * val[cc];
      curr++; 
      cc--;
    }
    cout << ans << endl;
  return 0;
} //good night.