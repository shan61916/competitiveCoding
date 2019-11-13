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
ll n, k;
ll modd = (ll)(1e9+9);
ll modadd(ll x, ll y) {
  return (x%modd + y%modd)%modd;
}
ll modkadd(ll x, ll y) {
  return (x%k + y%k)%k;
}
ll bitval[130];
ll fast_exp(ll base, ll exp) {
    if(bitval[exp] != -1) return bitval[exp];
    ll &res =bitval[exp];
    res = 1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%k;
       base=(base*base)%k;
       exp/=2;
    } 

    return res = res%k;
}
ll dp[129][1001][129];
ll recurse(ll idx, ll tot, ll xx) {
  if(idx == n) {
    if(tot%k == 0) return xx;
    return 0;
  }
  ll &ans = dp[idx][tot][xx];
  if(ans != -1) return ans;
  ans = 0;
  ans = modadd(ans, recurse(idx+1, tot, xx));
  ans = modadd(ans, recurse(idx+1, modkadd(tot, fast_exp(2, idx)), xx+1));
  return ans;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> k >> n;
  memset(dp, -1, sizeof(dp));
  memset(bitval, -1, sizeof(bitval));
  ll ans = recurse(0, 0, 0);
  cout << ans << endl;
  return 0;
} //good night.