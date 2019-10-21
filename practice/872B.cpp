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
const ll MAXN = (ll)(1e6 + 5);
const ll LIM  = (ll)(20);
const ll inf = (ll)(1e9 + 7);
vector<ll> logs(LIM);
vector<ll> p2(LIM);
vector<ll> arr(MAXN);
vector<vector<ll>> sparse(LIM, vector<ll>(MAXN, inf));

/* 

Pre-computing Logs and Powers of 2 to ensure O(1) query
*/

auto merge(ll a, ll b) -> ll {
   return min(a, b);
}

auto precompute() -> void {
	logs[1] = 0;
	for(ll i = 2; i < LIM; i++) {
		logs[i] = logs[i/2] + 1;
	}
	for(ll i = 0; i < LIM; i++) {
		p2[i] = (ll)(1ll<<i);
	}
}

auto build (ll n) -> void {
	for(ll i = 0; i < n; i++) sparse[0][i] = arr[i];

	for(ll i = 1; i <= logs[n]; i++) {
		ll x = n - p2[i], y = p2[i-1];
		for(ll j = 0; j <= x; j++) {
			sparse[i][j] = merge(sparse[i-1][j], sparse[i-1][j+y]);
		}
	}
    
}

auto query (ll i, ll j) -> ll {
	ll x = logs[j - i + 1];
	return merge(sparse[x][i], sparse[x][j - p2[x] + 1]) ;
}


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  precompute();	
  for(ll tc = 1; tc <= T; tc++){
  	cout << "Scenario #" << tc << ":" << endl;
    ll q, n;
    cin >> n >> q;
    for(ll i = 0; i < n; i++) cin >> arr[i];
    sparse.assign(LIM, vector<ll>(n+1, inf));
    build(n);
    while(q--) {
    	ll x, y;
    	cin >> x >> y;
    	// if(y < x) swap(x, y);
    	--x;
        ll ans = query(x, y);
        cout << ans << endl;
    }
  }
  return 0;
} //good night.