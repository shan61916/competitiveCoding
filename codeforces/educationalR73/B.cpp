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
ll n;
bool good(ll x, ll y) {
	if(x >= 0 and x < n and y >= 0 and y < n) return true;

	return false;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  vector<vector<bool>> visited(n, vector<bool> (n, false));
  queue<pair<ll, ll>> qu;
  ll dist[n][n];
  memset(dist, 0, sizeof(dist)); 
  ll dx[] = {1,1,2,2,-1,-1,-2,-2}; 
  ll dy[] = {2,-2,1,-1,2,-2,1,-1};
  char ans[n][n];
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) ans[i][j] = 'W';
  }
  dist[0][0] = 0;
  visited[0][0] = true;
  qu.push(mp(0, 0));
  while(!qu.empty()) {
  	pll x = qu.front();
  	// if(x.ff == 1 and x.ss == 2) cout << -111;
  	qu.pop();
    if(dist[x.ff][x.ss]%2 == 0) ans[x.ff][x.ss] = 'W' ;
    else ans[x.ff][x.ss] = 'B';

    // cout << x.ff << " " << x.ss << endl;

    for(ll i = 0; i < 8; i++) {
    	ll nx = x.ff + dx[i];
    	ll ny = x.ss + dy[i];
        // if(x.ff == 0 and x.ss == 0) cout << nx << " " << ny << endl;
    	if(good(nx, ny) and visited[nx][ny] == false) {
    		
    		qu.push(mp(nx, ny)) ;
    		visited[nx][ny] = true;
    		dist[nx][ny] = dist[x.ff][x.ss] + 1;
    	}
    }
  }
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) cout << ans[i][j];
  	cout << endl;
  }
  return 0;
} //good night.