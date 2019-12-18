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
  ll n;
  cin >> n;
  vll a(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    // if(a[i] > 0) foo = true;
  }
  ll res = 1;
  ll enc = 0;
  vector<ll> ans(n, 0);
  for(ll i = 0; i < n; i++) {
    if(a[i] == 0) {
      res = (res%mod * (3 - enc)%mod)%mod;  
      ans[0]++;
      enc++;
      continue;
    }
    res = (res%mod * (ans[a[i] - 1])%mod)%mod;
    ans[a[i]-1]--;
    ans[a[i]]++;
  }
  cout << res << endl;
  return 0;
} //good night.