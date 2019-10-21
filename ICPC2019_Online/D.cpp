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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> arr(k);
    vector<set<ll>> given(20);
    for(auto &x : arr) cin >> x;
    for(ll i = 0; i < k; i++) {
    	for(auto et : arr[i]) {
            given[et -'a'].insert(i);
    	}
    }
    vll ans(n, 0);
    set<ll> currset = given[s[0]-'a']; 
    ll last = 0;
    for(ll i = 0; i < n; i++) {
      set<ll> pres = currset;
      set<ll> intersect;
      set<ll> i2 = given[s[i] -'a'];
      ll x = *currset.begin();
      set_intersection(currset.begin(),currset.end(),i2.begin(),i2.end(),std::inserter(intersect,intersect.begin()));
      currset = intersect;
      if(currset.size() == 0) {
    	  ans[last] += x;
    	  ans[i-1]-= x;
      }
  }
   for(ll i = 1; i < n; i++) {
      ans[i]+= ans[i-1];
   }
   for(auto it: ans )cout << it + 1 << " ";
}
  return 0;
} //good night.