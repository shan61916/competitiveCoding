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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++){
      cin >> a[i];  	
  }
  ll inc;
  cin >> inc;
  vll b ;
  for(ll i = 0; i < n; i++) {
  	ll x = a[i] - k ;
  	ll zz = 0;
  	if(x%inc) zz++;
  	zz+=(x/inc);
    if(x < 0) zz = 0;
  	b.pb(max(0ll, zz));
  }
  vll c(n+1);
  for(ll i = 0; i < n; i++) {
  	ll x;
  	cin >> x;
  	c[i+1] = (x);	
  }
  // sort(c.begin()+1, c.end());
  c[0] = 0;
  ll tt = 0;
  for(ll i = 1; i <= n; i++) c[i]+= c[i-1];
  bool foo = true;
  for(ll i = 0; i < n; i++) {
  	if(b[i] > i+1) foo = false;
  	else {
  		tt = max(tt, c[b[i]] - c[i+1 - b[i]]);
  	}
  }
  if(!foo) cout << -1;
  else cout << tt << endl;
  return 0;
} //good night.