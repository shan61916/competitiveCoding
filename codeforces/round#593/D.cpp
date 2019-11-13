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
ll n, m, k;
map<pair<ll, ll>, ll> key;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};
bool dfs(ll x, ll y, ll dir, ll tot) {
	if(tot == ((n*m) - k - 1)) return true;
    bool foo = false;
    ll p1 = x + dx[dir];
    ll p2 = y + dy[dir];
    if(p1 < n and p2 < m and p1 >= 0 and p2 >= 0 and key[mp(p1, p2)] != 1) {
    	foo|= dfs(p1, p2, dir, tot+1);
    }
    dir = (dir+1)%4;
    p1 = x + dx[dir];
    p2 = y + dy[dir];
    if(p1 < n and p2 < m and p1 >= 0 and p2 >= 0 and key[mp(p1, p2)] != 1) {
    	foo|= dfs(p1, p2, dir, tot+1);
    }

    return foo;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> m >> k;
  for(ll i = 0; i < k; i++) {
  	ll x, y;
  	cin >> x >> y;
  	--x, --y;
  	key[mp(x, y)] = 1;
  }
  bool foo = dfs(0, 0, 0, 0);
  foo ? cout << "Yes" : cout << "No";
  return 0;
} //good night.