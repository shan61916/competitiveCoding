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
vll ar;
ll n, a, b, k;
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> a >> b >> k;
  ar.resize(n);
  for(ll i = 0; i < n; i++) cin >> ar[i];
  vll todo(n);
  for(ll i = 0; i < n; i++) {
    ll gott = ar[i]%(b + a);
    if(gott <= a and gott != 0) {
    	todo[i] = 0;
    } else {
    	if(gott == 0) gott = b + a;
    	ll pp = ((gott + a - 1)/a);
    	todo[i] = (pp) - 1;
    }
  }
  sort(all(todo));
  ll tot = 0, ans = 0;
  for(ll i = 0; i < n; i++) {
  	tot+= todo[i];
  	if(tot <= k) {
  		ans++;
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.