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
ll dp[200010][3][3];
ll arr[200010][3];
ll n = 0;

ll recurse(ll curr, ll mode, ll dir) {
	// cout << curr << " " << mode << " " << dir << endl;
	if(curr == n) {
        if(mode == 1 and dir == 0	) return 1;
        return 0;
	}
	ll &ans = dp[curr][mode][dir];
	if(ans != -1) return ans;
	ans = 0;
	if(arr[curr][mode] == 1 or arr[curr][mode] == 2) {
		if(dir != 1) {
            ans|= recurse(curr+1, mode, dir);
		} 
	} else {
		if(dir == 1) {
			ans|= recurse(curr+1, mode, dir^1);
		} else {
			ans|= recurse(curr, mode^1, dir^1);
		}
	}
	return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   cin >> n;
   string s;
   cin >> s;
   for(ll i = 0; i < n; i++) arr[i][0] = s[i] -'0';
   cin >> s;
   for(ll i = 0; i < n; i++) arr[i][1] = s[i] -'0';
   memset(dp, -1, sizeof(dp));
   ll ans = recurse(0, 0, 0);
   ans ? cout << "YES" : cout << "NO";
   cout << endl;
  }
  return 0;
} //good night.