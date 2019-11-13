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
   vll a(2*n+1); 
   for(ll i = 1; i <= 2*n; i++) cin >> a[i];
   ll mx = 0;
   for(ll i = 1; i <= n; i++) {
     mx = max(mx, a[i] + a[2*n - i + 1]);
   }
   cout << mx << endl;
  }
  return 0;
} //good night.