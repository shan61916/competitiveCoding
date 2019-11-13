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
const ll inf = (ll)(1e9+7);
string s;
ll n, a, b, c;
ll dp[101][101][101]; 
ll can(char x, ll y) {
	if(x == 'R' and y == 2) return 1;
	if(x == 'P' and y == 3) return 1;
	if(x == 'S' and y == 1) return 1;
	return 0;
}
ll recurse(ll idx, ll x, ll y) {
	if(idx == n and x == a and y == b and (n - x - y) == c) return 0;
	else if(idx == n) return -inf; 
	ll &ans = dp[idx][x][y];
	if(ans != -1) return ans;
	ans = -inf;
	ans = can(s[idx], 1) + recurse(idx+1, x+1, y);
	ans = max(ans, can(s[idx], 2) + recurse(idx+1, x, y+1)); 
	ans = max(ans, can(s[idx], 3) + recurse(idx+1, x, y));
	return ans;
}
void trace(ll idx, ll x, ll y) {
	if(idx == n) return;
    ll ans = recurse(idx, x, y);
    if(can(s[idx], 1) + recurse(idx+1, x+1, y) == ans) {
    	cout << 'R';
    	trace(idx+1, x+1, y);
    	return;
    }
    if(can(s[idx], 2) + recurse(idx+1, x, y+1) == ans) {
    	cout << 'P';
    	trace(idx+1, x, y+1);
    	return ;
    }
    if(can(s[idx], 3) + recurse(idx+1, x, y) == ans) {
    	cout << 'S';
    	trace(idx+1, x, y);
    	return ;
    }
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   cin >> n >> a >> b >> c;
   cin >> s;
   memset(dp, -1, sizeof(dp)); 
   ll ans = recurse(0, 0, 0);
   if(ans >= (n+1)/2) {
   	cout << "Yes" << endl;
   	trace(0, 0, 0);
   	cout << endl;
   } else {
   	cout << "No" << endl;
   }
  }
  return 0;
} //good night.