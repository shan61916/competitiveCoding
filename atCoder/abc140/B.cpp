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
  vector<ll> a(n), b(n), c(n, 0);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i];
  	a[i]--;
  }
  for(ll i = 0; i < n; i++) cin >> b[i] ;
  for(ll i = 0; i < n-1; i++) cin >> c[i];
  ll prev = -2, tot = 0;
  for(ll i = 0; i < n; i++) {
  	tot+= b[a[i]];
  	if(prev+1 == a[i]) tot+= c[prev]; 
  	prev = a[i];
  }
  cout << tot << endl;
  return 0;
} //good night.