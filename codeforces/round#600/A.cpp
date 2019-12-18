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
   ll n, k;
   cin >> n;
   vll a(n), b(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   for(ll i = 0; i < n; i++) cin >> b[i]; 
   bool fo = true; 
   for(ll i = 0; i < n; i++) {
      if(a[i] == b[i]) continue;
      k = b[i] - a[i];
      ll j = i; 
      if(k < 0) {
        fo = false;
        break;
      }
      while(j < n and a[j] + k == b[j]) {
        a[j] = b[j];
        j++;
      }
     break;
   }
   for(ll i = 0; i < n; i++) if(a[i] != b[i]) fo = false;
   fo ? cout << "YES" : cout << "NO";
   cout << endl;
  }
  return 0;
} //good night.