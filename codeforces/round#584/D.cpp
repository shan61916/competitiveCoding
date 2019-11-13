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
const int MAX = 1e3 + 3;
const int MOD = 998244353;

int ncr[MAX][MAX];

void pascal() {
  for (int i = 0; i < MAX; ++i) {
    ncr[i][0] = ncr[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
      if (ncr[i][j] >= MOD) ncr[i][j] -= MOD;
    }
  }
}
ll modadd(ll x, ll y) {
  return (x%MOD + y%MOD)%MOD;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  pascal();
  ll n;
  cin >> n;
  vll a(n);
  for(auto &x : a) cin >> x;
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
    if(a[i] < 1) continue;
    ans = modadd(ans, ncr[n - i - 1][a[i]]);
  }
  cout << ans << endl;
  return 0;
} //good night.