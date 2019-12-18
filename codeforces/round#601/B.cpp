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
  ll n, m;
  cin >> n >> m;
  // cout << n << " " << m << endl;
  vector<pll> a(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i].ff;
    a[i].ss = i+1;
  }
  sort(all(a));
  if(m < n) {
    cout << -1 << endl;
    continue;
  }
  if(n <= 2) {
  cout << -1 << endl;
  continue;
  }
  ll anss = 0;
  vector<pll> ans;
  for(ll i = 1; i < n; i++) {
    anss+= a[i-1].ff + a[i].ff;
    ans.pb(mp(a[i-1].ss, a[i].ss));
  }
  anss+= a[n-1].ff + a[0].ff;
  ans.pb(mp(a[n-1].ss, a[0].ss));
  ll left = m - (ans.size());
  for(ll i = 0; i < left; i++) {
    anss+= a[0].ff + a[1].ff;
    ans.pb(mp(a[0].ss, a[1].ss));
  }
  cout << anss << endl;
  for(auto it : ans) {
    cout << it.ff << " " << it.ss << endl;
  }
}
  return 0;
} //good night.