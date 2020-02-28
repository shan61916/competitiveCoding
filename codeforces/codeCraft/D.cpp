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
ll dx[] = {1, -1 ,0, 0};
ll dy[] = {0, 0, 1, -1};
char order[] = {'U', 'D', 'L', 'R'};
char anti[] = {'D', 'U', 'R', 'L'};
pll a[1001][1001];
char ans[1001][1001];
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vector<vector<bool>> visited(n, vector<bool> (n, false));
  queue<pll> q;
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) ans[i][j] = 'P';
  }
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++){ 
  		ll x, y;
  		cin >> x >> y; 
  		a[i][j] = mp(x, y);
  		if(x == i + 1 and y == j + 1) {
  			q.push(mp(i, j));
  			ans[i][j] = 'X';
  			visited[i][j] = true;
  		}
  	}
  }
  while(!q.empty()) {
  	pll xx = q.front();
  	q.pop(); 
  	for(ll i = 0; i < 4; i++) {
  		ll nx = xx.ff + dx[i]; 
  		ll ny = xx.ss + dy[i];
  		if(nx >= 0 and nx < n and ny >= 0 and ny < n and visited[nx][ny] == false) {
  			if(a[nx][ny] == a[xx.ff][xx.ss]) {
  				ans[nx][ny] = order[i];
  				visited[nx][ny] = true;
  				q.push(mp(nx, ny));
  			}
  		} 
   	}
  }
  set<pll> bad; 
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) {
  		if(ans[i][j] == 'P' and a[i][j].ff  == -1 and a[i][j].ss == -1 and bad.find(mp(i, j)) == bad.end()) {
  			bool foo = false;
  			for(ll k = 0; k < 4; k++) {
  				ll nx = i + dx[k];
  				ll ny = j + dy[k];
  				if(nx >= 0 and nx < n and ny >= 0 and ny < n and a[nx][ny].ff == -1 and a[nx][ny].ss == -1) {
  					 if(bad.count({nx, ny}) == 0) {
  					 	 ans[i][j] = anti[k]; 
  					 	 ans[nx][ny] = order[k]; 
  					 	 bad.insert({nx, ny});
  					 	 foo = true;
  					 	 bad.insert({i, j});
  					 } else {
  					 	ans[i][j] = anti[k];
  					 	foo = true;
  					 	bad.insert({nx, ny});
  					 }
  				}
  			}
  			if(foo == false){
  				cout << "INVALID";
  				return 0;
  			}
  		}
  	}
  }
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) {
  		if(ans[i][j] == 'P') {
  			cout << "INVALID";
  			return 0;
  		}
  	}
  }
  cout << "VALID" << endl;;
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) {
  		cout << ans[i][j];
  	}
  	cout << endl;
  }
  return 0;
} //good night.