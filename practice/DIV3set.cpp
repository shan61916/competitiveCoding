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
string s;
ll k;
ll n;
ll sz;
bool visited[101][101][28] ;
ll cost[28][28];
ll dp[101][101][28];
ll recurse(ll idx, ll done, ll prev) {
	if(idx == sz) {
		if(done <= k) return 0;
		else return -1000000000;
	}
	if(visited[idx][done][prev] == true) return dp[idx][done][prev];
	visited[idx][done][prev] = true;
	ll &ans = dp[idx][done][prev];
    ans = -100000000;
	for(ll i = 0; i < 26; i++) {
		if(i != (ll)(s[idx] - 'a'))  ans = max(ans, cost[prev][i] + recurse(idx+1, done+1, i)) ;
		else ans = max(ans, cost[prev][i] + recurse(idx+1, done, i)) ;
	}
	return ans;
} 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> s;
  cin >> k;
  sz = s.length(); 
  cin >> n;
  memset(cost, 0, sizeof(cost));
  for(ll i = 0; i < 28; i++) {
  	for(ll j = 0; j < 28; j++) {
  		cost[i][j]  = 0;	
  	}
  }
  memset(visited, false, sizeof(visited));
  for(ll i = 0; i < n; i++) {
  	char x, y;
  	cin >> x >> y;
  	ll z;
  	cin >> z;
  	cost[x-'a'][y-'a'] = z;
  }
  ll ans = recurse(0, 0, 27);
  cout << ans;
  return 0;
} //good night.