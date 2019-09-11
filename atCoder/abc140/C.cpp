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
  vector<ll> a(n);
  vector<ll> b(n-1);
  for(ll i = 0; i < n-1; i++) cin >> b[i];
  a[0] = INT_MAX;  
  for(ll i = 0; i < n-1; i++) {
  	 if(a[i] > b[i]) a[i] = b[i];
  	 a[i+1] = b[i];
  }
  ll ans = 0;
  for(auto it: a) ans+= it;
  cout << ans << endl;
  return 0;
} //good night.