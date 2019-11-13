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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    ll n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    vector<vector<bool>> vis(26, vector<bool>(26, false));
    for(int i = 0; i <= n-k; i++) {
    	vis[a[i]-'a'][a[i+k-1]-'a'] = true;
    }
    vector<int> ct(26, 0);
    ll ans = 0;
    for(auto it: b) ct[it -'a']++;
    for(int i = 0; i < m; i++) {
    	if(ct[b[i] - 'a']) {
    		ll xx = (ll)(b[i]-'a');
    		for(int j = 0; j < 26; j++) {
    			if(vis[xx][j] and ct[j]) {
    				ans+= ct[j];
    			}
    		}
    		ct[xx]--;
    	}
    }
    cout << ans << endl;
  }
  return 0;
} //good night.