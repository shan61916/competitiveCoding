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
  vector<ll> arr;
  for(ll i = 1; i <= n*n; i++) {
  	arr.pb(i);
  }
  ll ct = 0;
  for(ll i = 0; i < n*n; i+=n) {
  	if(ct == 1) {
  		// cout << i << " " << i+n << endl;
  		reverse(arr.begin() + i, arr.begin() + i + n); 
  	}
  	ct^=1;
  }
  for(int i = 0; i < n; i++) {
  	 for(ll j = 0; j < n; j++) {
  	 	cout << arr[i + (j*n)] << " ";
  	 }
  	 cout << endl;
  }
  return 0;
} //good night.