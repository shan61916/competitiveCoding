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
   ll n, m;
   cin >> n;
   ll o1 = 0, e1 = 0;
   for(ll i = 0; i < n; i++) {
   	ll tp;
   	cin >> tp;
   	if(tp%2) o1++;
   	else e1++;
   }
   cin >> m;
   ll ans = 0;
   for(ll i = 0; i < m; i++) {
   	ll tp;
   	cin >> tp;
   	if(tp%2)ans+= o1;
   	else ans+= e1;
   }
   cout << ans << endl;
  }
  return 0;
} //good night.