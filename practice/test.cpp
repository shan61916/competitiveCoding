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
ll n, m;
string s;

ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}
ll recurse(ll idx, ll sum) {
  if(idx == n) {
    if(sum%m == 0) return 1;
    return 0;
  }
  ll ans = 0;
  if(s[idx] == '_') {
   ans = ans + recurse(idx+1, (sum%m + fast_exp(2, n-1-idx)%m)%m) ;
   ans = ans + recurse(idx+1, sum%m);
  } else if(s[idx] == '1') {
    ans = ans + recurse(idx+1, (sum%m + fast_exp(2, n-1-idx)%m)%m) ;
  } else if(s[idx] == '0') {
    ans = ans + recurse(idx+1, sum%m);
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
   cin >> n >> m;
   cin >> s;
   // memset(dp, -1, sizeof(dp));
   ll ans = recurse(0, 0);
   cout << ans << endl;   
  }
  return 0;
} //good night.