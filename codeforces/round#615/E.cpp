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
  ll n, m;
  cin >> n >> m;
  ll arr[n + 1][m + 1];
  for(ll i = 1; i <= n; i++) {
  	for(ll j = 1; j <= m; j++) cin >> arr[i][j];
  } 
  ll ans = 0;
  for(ll i = 1; i <= m; i++) {
  	ll res = inf;
  	vll colomn;
  	for(ll j = 1; j <= n; j++)colomn.pb(arr[j][i]);
  	for(ll j = 1; j <= n; j++) colomn.pb(arr[j][i]);
  	ll next = i;
    queue<ll> q;
  	for(ll k = 0; i < 2*n; k++) {
  		if(colomn[k] == next){
  			 q.push(k);
  			 next+=n;
  			 if(next > m*n) next = i;
  		}
  		// if(k >= n) {
  		// 	ll pp = k%n;
  		// 	if(colomn[q.front()] == colomn[pp]) q.pop();
  		// }
  		// if(k >= n-1) {
  		// 	res = min(res, m - (ll)q.size() + (k - n - 1));
  		// }
  // 	}
  // 	ans+= res;
  }
  cout << ans << endl;
  return 0;
} //good night.