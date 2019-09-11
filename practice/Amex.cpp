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
ll n, x;
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
   ll T;
   cin >> T;
   while(T--){
  cin >> n >> x;
  ll xx = __builtin_popcountll(x);
  vector<ll> a(n, 0);
  if(n == 1) {
  	cout << x ;
  } else if(xx >= n) {
  	ll zz = 0;
    for(ll i = 0; i <=63; i++) {
    	if(x&(1ll<<i)) {
    		a[zz++]+= (ll)(1ll<<i); 
    		if(zz >= n) zz = n-1;
    	}
    }
    for(auto it: a) cout << it << " ";
  } else {
  	if(x == 1) {
  		if(n%2) {
  			for(ll i = 0; i < n; i++) cout << 1 << " ";
  		} else {
  			for(ll i = 0; i < n-2; i++) cout << "1 ";
  			cout << 2 << " " << 3;
  		}
  	} else {
  		if((n - xx)%2 == 0) {
  			ll zz = 0;
  			for(ll i = 0; i < 64; i++) {
  				if(x&(1ll<<i)) {
  					a[zz++]+= (1ll<<i);
  				}
  			}
  			for(ll i = zz; i < n; i++) a[i] = 1;
  			sort(all(a));
  		    for(auto it: a) cout << it << " ";
  		} else {
  			 ll zz = 0;
  			 for(ll i = 0; i <=63; i++) {
    	     if(x&(1ll<<i)) {
    		  a[zz++]+= (ll)(1ll<<i); 
    		  if(zz >= n) zz = 1;
    	}   
    }       
            ll tx = zz - 1;
  			for(ll i = zz; i < n; i++) {
                  a[i] = 1;
                  a[tx]^=1;
  			}
  			sort(all(a));	
  			if(a[n-1]%2) {
  				a[n-1] = a[n-1]-1;
  				a[n-1]+=a[n-2];
  				a[n-2] = 1;
  			}
  			sort(all(a));
            for(auto it: a) cout << it << " ";
            // cout << x << endl;

  		}
  	}
  }
  cout << endl;
}
  return 0;
} //good night.