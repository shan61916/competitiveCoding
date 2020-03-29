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
ll h, w;
vector<string> grid;
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
bool ok(ll x, ll y) {
	if(x < h and x >= 0 and y < w and y >= 0 and grid[x][y] == '.') return true;
  return false;
}
ll dist(pll a, pll b) {
	queue<pll> q;
	vector<vll> visited(40, vll(40, 0));
	vector<vll> dist(40, vll(40, inf));
	dist[a.ff][a.ss] = 0;
	visited[a.ff][a.ss] = 1;
	q.push(a);
	while(!q.empty()) {
		pll gv = q.front();
		q.pop();
		if(gv == b) break;
		for(ll i = 0; i < 4; i++) {
			ll nx = gv.ff + dx[i];
			ll ny = gv.ss + dy[i];
			if(ok(nx, ny) and visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				dist[nx][ny] = 1 + dist[gv.ff][gv.ss];
				// cout << nx << " " << ny << endl;
				q.push(mp(nx, ny));
			}
		}
	}
	return dist[b.ff][b.ss];
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> h >> w;
  grid.resize(h);
  for(ll i = 0; i < h; i++) {
  	cin >> grid[i];
  }
  vector<pll> times;
  for(ll i = 0; i < h; i++) {
  	for(ll j = 0; j < w; j++) {
  		if(grid[i][j] == '.') times.pb(mp(i, j));
  	}
  }
  ll ans =  0;
  for(auto it: times) {
  	for(auto et : times) {
  		ans = max(ans, dist(it, et));
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.