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
   vll arr(n);
   for(ll i = 0; i < n; i++) cin >> arr[i];
   ll ans = 0;
   sort(all(arr));
   ans = arr[0]*arr[n-1];
   vll pp;
   for(ll i = 2; i*i <= ans; i++) {
   	if(ans%i == 0) {
   		if(ans/i == i) {
   			pp.pb(i);
   		} else {
   			pp.pb(i);
   			pp.pb(ans/i);
   		}
   	}
   }
   sort(all(pp));
   ll n2 = pp.size();
   bool foo = true;
   if(n != n2) foo = false;
   if(foo) {
   	for(ll i = 0; i < n; i++) if(pp[i] != arr[i]) foo = false;
   }
   if(!foo) {
   	cout << -1 << endl;
   } else {
   	cout << ans << endl;
   }
 }
  return 0;
} //good night.