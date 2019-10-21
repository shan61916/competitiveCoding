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
    ll n;
    cin >> n;
    map<string, ll> xo; 
    map<string, ll> ox;
    set<string> tot;
    for(ll i = 0; i < n; i++) {
    	string x;
    	ll p;
    	cin >> x >> p;
    	tot.insert(x);
    	if(p == 1) {
    		xo[x]++; 
    	} else {
    		ox[x]++;
    	}
    }
    ll ans = 0;
    for(auto it: tot) {
       ans+= max(ox[it], xo[it]);
    }
    cout << ans << endl;
  }
  return 0;
} //good night.