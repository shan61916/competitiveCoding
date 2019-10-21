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
  vll a(n);
  for(auto &x : a) cin >> x;
  ll cycles = k/n;
  vll done(n, 0);
  for(ll i = 0; i < n; i++) {
  	done[i]+= cycles;
  	if(i < k%n) {
  		done[i]+=1;
  	}
  }
  vll ans(n, 0);
  for(ll i = 0; i < n; i++) ans[i] = a[i];
  for(ll i = 0; i < n; i++) {
  	if(n%2 == 0 and i == n/2 and done[i]) ans[i] = 0;
  	if(i < n/2) {
  		if(done[i]%3 == 1) {
  			ans[i] = a[i]^(a[n - (i%n) - 1]) ;
  		} else if(done[i]%3 == 2) {
  			ans[i] = a[n - (i%n) - 1];
  		} else ans[i] = a[i];
  	} else {
  		if(done[i]%3 == 1) {
  			ans[i] = (a[n - (i%n) - 1]) ;
  		} else if(done[i]%3 == 2) {
  			ans[i] = a[i]^a[n - (i%n) - 1];
  		} else ans[i] = a[i];
  	}
  }
  for(auto it: ans) cout << it << " ";
  cout << endl;
  } 
  return 0;
} 