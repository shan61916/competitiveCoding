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
ll l, r;
ll dp[40][3][3][3][3];
vector<ll> a(40, 0), b(40, 0);
ll recurse(ll idx, ll t1, ll t2, ll t3, ll t4) { 
  if(idx == 40) {
    return 1;
  }
  ll &ans = dp[idx][t1][t2][t3][t4]; 
  if(ans != -1) return ans;
  ll f1, f2, to1, to2; 
  f1 = a[idx];
  f2 = a[idx];
  to1 = b[idx]; 
  to2 = b[idx];
  if(t1) f1 = 0;
  if(t2) to1 = 1;
  if(t3) f2 = 0;
  if(t4) to2 = 1;
  ans = 0;
  for(ll i = f1; i <= to1; i++) {
    for(ll j = f2; j <= to2; j++) {
      if(i != j or ((i|j)==0)) {
           ans+=recurse(idx+1, t1|(i > a[idx]), t2|(i < b[idx]), t3|(j > a[idx]), t4|(j < b[idx]));
      } 
    }
  }
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
  cin >> l >> r;
  a.assign(40, 0);
  b.assign(40, 0);
  for(ll i = 0; i < 40; i++) {
    if(l&(1ll<<i)) a[i] = 1;
     if(r&(1ll<<i)) b[i] = 1;
  }
  reverse(all(a));
  reverse(all(b));
  // for(auto it: b) cout << it ;
  memset(dp, -1, sizeof dp);
  cout << recurse(0, 0, 0, 0, 0) << endl;
 }
  return 0;
} //good night.

