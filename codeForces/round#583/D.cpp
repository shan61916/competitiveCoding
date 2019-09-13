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
  vector<vector<bool>> visited;
  vector<vector<ll>> dp;
  vector<string> a;
  bool isvalid(ll x, ll y) {
  	if(x > n-1 or y > m-1) return 0;
  	if(a[x][y] == '#') return 0;
  	return 1;
  }
  void dfs(ll x, ll y) {
     visited[x][y] = true;
     // if(x == n-1 and y == m-1) return ;
     if(isvalid(x+1, y) and !visited[x+1][y]) dfs(x+1, y);
     if(isvalid(x, y+1) and !visited[x][y+1]) dfs(x, y+1);
  }
  ll recurse(ll x, ll y) {
  	if(!isvalid(x, y)) return false;
  	if(x == n-1 and y == m-1) return true;
  	if(dp[x][y] != -1) return dp[x][y];
  	ll &ans = dp[x][y]; 
  	ans = 0;
  	ans|=recurse(x+1, y);
  	ans|= recurse(x, y+1);
  	return ans;
  }
  int main(){
   IOS
  #ifdef SHAN
      freopen("input.txt" , "r" , stdin);  
  #endif 
    cin >> n >> m;
    visited.resize(n, vector<bool>(m, false));
    dp.resize(n, vector<ll>(m, -1));
    a.resize(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    dfs(0, 0);
    if(!visited[n-1][m-1]) {

    	cout << 0;
    	return 0;
    }
    vector<ll> layer(n+m, 0);
    for(ll i = 0; i < n; i++) {
    	for(ll j = 0; j < m; j++) {
    		if(visited[i][j] and recurse(i, j)) {
    			layer[i+j]++;
    		}
    	}
    }
    ll ans = INT_MAX;
    for(ll i = 1; i < n+m-2; i++) {
    	ans = min(ans, layer[i]);
    }
    cout << ans << endl;
    return 0;
  } //good night.