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
   vector<ll> a(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   ll start = 0;
   while(start < n-1) {
       ll mx = INT_MAX, id = -1;
       for(ll j = start; j < n; j++) {
       	 if(a[j] <= mx) {
       	 	mx = a[j], id = j;
       	 }
       }
       if(id == start) {
       	start++;
       	continue;
       } else {
         for(ll k = id; k > start; k--) {
         	swap(a[k], a[k-1]);
         }
         start = id;
       }
   }
   for(auto it: a) cout << it << " ";
   cout << endl;
  }
  return 0;
} //good night.