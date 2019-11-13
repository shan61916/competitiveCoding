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
const ll mx = (ll)(1e9);
bool comp(ll a, pair<ll, pll> b) {
  return (a  < b.first);
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    ll m, k, ans = 0;
    cin >> m >> k;
    vector<pair<ll, pll>> arr;
    vector<pair<ll, pll>> brr;
    for(ll i = 1; i <= m; i++) {
      ll x, y, z;
      cin >> x >> y >> z;
      arr.pb(mp(x, mp(y, z)));
      brr.pb(mp((mx - y), mp((mx - x), z)));
    }
    sort(all(arr));
    sort(all(brr));
    vll c1(m), c2(m);
    for(ll i = 0; i < m; i++) {
      c1[i] = (arr[i].ss.ff - arr[i].ff + 1) * arr[i].ss.ss;
      c2[i] = (brr[i].ss.ff - brr[i].ff + 1) * brr[i].ss.ss;
    }
    for(ll i = 1; i < m; i++) {
      c1[i]+= c1[i-1];
      c2[i]+= c2[i-1];
    }
    for(ll i = 0; i < m; i++) {
      ll curr = arr[i].ff;
      ll next = curr + k - 1;
      ll nextidx = upper_bound(all(arr), next, comp) - arr.begin();
      nextidx--;
      ll currsum = 0;
      if(nextidx != 0) currsum+= c1[nextidx-1];
      if(i != 0) currsum-= c1[i-1];
      ll lastidx = arr[nextidx].ff;
      ll rem = max(0LL, k - (lastidx - arr[i].ff));
      currsum+= min(rem, arr[nextidx].ss.ff - arr[nextidx].ff+1) * arr[nextidx].ss.ss;
      ans = max(ans, currsum);
    }
    for(ll i = 0; i < m; i++) {
    ll curr = brr[i].ff;
    ll next = curr + k - 1;
    ll nextidx = upper_bound(all(brr), next, comp) - brr.begin();
    nextidx--;
    ll currsum = 0;
    if(nextidx != 0) currsum+= c2[nextidx-1];
    if(i != 0) currsum-= c2[i-1];
    ll lastidx = brr[nextidx].ff;
    ll rem = max(0LL, k - (lastidx - brr[i].ff));
    currsum+= min(rem, brr[nextidx].ss.ff - brr[nextidx].ff+1) * brr[nextidx].ss.ss;
    ans = max(ans, currsum);
  }
  cout << ans << endl;
 }
  return 0;
} //good night.