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
const ll inf = (ll)(1e17);

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, k;
  cin >> n >> k;
  vll a(n+1);
  a[0]=0;
  for(ll i = 1; i <= n; i++) cin >> a[i] ;
  for(ll i = 1; i <= n; i++) a[i]+= a[i-1]; 
  ll mn = inf;
  // for(auto it: a) cout << it << " ";
  for(ll i = 0; i <= n; i++) {
    ll xx = a[i] + k;
    ll idx;
    // cout << xx << endl;
    auto it = lower_bound(a.begin(), a.end(), xx);
    if(it != a.end()) idx = it - a.begin();
    else if(it == a.end()) {
        idx = n ;
    }
    // cout << idx << endl;
    for(ll j = max(0ll, idx-1); j <= min(n, idx+1); j++) {
        mn = min(mn, abs(xx    - a[j]));
    }
  }
  cout << mn << endl;
  return 0;
} //good night. 