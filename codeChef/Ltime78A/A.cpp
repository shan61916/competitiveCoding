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
   vector<vll> a(n, vll(m, 0));
   for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) cin >> a[i][j];
   }
   ll dp[n][m];
   ll ans[n][m];
   for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) ans[i][j] = 1;
   }
   for(ll i = 0; i < m; i++) dp[0][i] = a[0][i];
   for(ll i = 1; i < n; i++) {
    for(ll j = 0; j < m; j++) {
       dp[i][j] = 0;
       if(i-1 >= 0 and j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
       if(i-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
       if(i-1 >= 0 and j+1 < m) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
       if(dp[i][j] < a[i][j]) ans[i][j] = 1;
       else ans[i][j] = 0;
       dp[i][j] = max(dp[i][j], a[i][j]);
    }
   }
   for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) cout << ans[i][j];
    cout << endl;
   }
  }
  return 0;
} //good night.