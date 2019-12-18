  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   int ll;
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
const ll mx = (ll)(1LL<<20);
ll ct[21][21];
ll dp[mx];

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  memset(dp, 0, sizeof dp);
  memset(ct, 0, sizeof ct);
  for(ll i = 1; i < n; i++) {
    ct[s[i]-'a'][s[i-1] - 'a']++;
    ct[s[i-1] - 'a'][s[i] - 'a']++;
  }
  for(ll j = 0; j < mx; j++) {
  for(ll i = 0; i < m; i++) {
      ll turn = __builtin_popcount(j);
      for(ll k = 0; k < m; k++) {
        if(i == k) continue;
        dp[j^(1ll<<k)]+= dp[j];
        if(j&(1ll<<k)) {
          dp[j^(1ll<<i)]-= ct[i][k]*(turn + 1);
        } else {
          dp[j^(1ll<<i)]+= ct[i][k]*(turn + 1);
        }
      }
    }
  }
  cout << dp[0] << endl;
  // ll tot = (1ll<<m) -1;
  // cout << dp[tot] << endl;
  return 0;
} //good night.