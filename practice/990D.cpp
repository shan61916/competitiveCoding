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
vector<vll> comp(1001, vll(1001, 0));
vector<bool> visited(1001, false);
ll n, a, b;
void dfs(ll idx) {
	visited[idx] = true;
	for(ll i = 1; i <= n; i++) {
		if(!visited[i] and comp[idx][i] == 1) dfs(i);
	}
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> a >> b;
  if(a > 1 and b > 1) {
  	cout << "NO";
  	return 0;
  }
  bool foo = false;
  if(a > b) foo = true;
  if(foo)swap(a, b);
  vector<vll> adj(n+1, vll(n+1, 0));
  ll todo = n - (b-1);
  for(ll i = 2; i <= todo; i++) {
    adj[i][i-1] = 1;
    adj[i-1][i] = 1;
  }
  for(ll i = 1; i <= n; i++) {
  	for(ll j = 1; j <= n; j++) {
  		if(i == j) continue;
  		if(!adj[i][j]) comp[i][j] = 1;
  	}
  }
  visited.assign(1001, false);
  ll ct = 0;
  for(ll i = 1; i <= n; i++) {
  	if(!visited[i]){
  		ct++;
  		dfs(i);
  	}
  }
  if(ct != a) {
  	cout << "NO";
  	return 0;
  }
  cout << "YES" << endl;
  if(foo) {
  	for(ll i = 1; i <= n; i++) {
  		for(ll j = 1; j <= n; j++) {
  			cout << adj[i][j];
  		}
  		cout << endl;
  	}
  } else {
  	for(ll i = 1; i <= n; i++) {
  		for(ll j = 1; j <= n; j++) {
  			cout << comp[i][j];
  		}
  		cout << endl;
  	}  	
  }
  return 0;
} //good night.