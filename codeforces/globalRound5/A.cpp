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
  ll n;
  cin >> n;
  vll a(n);
  ll odd = 0;
  for(auto &it : a) cin >> it;
  for(auto it : a) {
  	if(it%2) {
  		odd++;
  	}
  }
  ll xx = 0;
  for(ll i = 0; i < n; i++) {
  	if(a[i]%2 == 0) {
  		cout << a[i]/2 << endl;
  	} else {
  		if(xx == 0) {
  			if(a[i] < 0) {
  				cout << a[i]/2; 
  			} else {
  				cout << a[i]/2 + 1;
  			}
  		} else {
  			if(a[i] < 0) {
  				cout << (a[i]/2) - 1;
  			} else cout << a[i]/2;
  		}
  		xx^=1;
  		cout << endl;

  	}
  }
  return 0;
} //good night.