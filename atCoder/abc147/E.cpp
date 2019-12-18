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
ll a[81][81];
ll b[81][81];
bool isvalid(ll x, ll y) {
  if(x <= h and y <= w) return true;
  return false;
}
ll ans[81][81];
void dfs(ll x, ll y) {
  if(!isvalid(x, y)) return;
  if(x == h and y == w) ans[h][w] = abs(a[h][w] - b[h][w]); 
  if(x == h and y == w) return;
  dfs(x+1, y);
  ans[x][y] = inf;
  ll i = x;
  ll j = y;
  ans[x][y] = min({ans[x][y], abs(a[i][j] - (ans[x+1][y] + b[i][j])), abs(b[i][j] - (ans[x+1][y] + a[i][j]))});
  dfs(x, y+1);
  ans[x][y] = min({ans[x][y], abs(a[i][j] - (ans[x][y+1] + b[i][j])), abs(b[i][j] - (ans[x][y+1] + a[i][j]))});
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> h >> w;
  for(ll i = 1; i <= h; i++) {
    for(ll j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for(ll i = 1; i <= h; i++) {
  for(ll j = 1; j <= w; j++) {
      cin >> b[i][j];
    }
  }
  dfs(1, 1);
  cout << ans[1][1] << endl;
  return 0;
} //good night.