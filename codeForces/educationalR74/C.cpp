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
   ll h, n;
   cin >> h >> n;
   map<ll, ll> key;
   vll a(n+1, 0);
   for(ll i = 0; i < n; i++) {
   	cin >> a[i];
    key[a[i]] = 1;
   }
   key[0] = 1;
   ll curr = h;
   ll last_idx = 0;
   ll ct = 0;
   while(curr > 0) {
   	 if(curr <= 2) break;
     if(key[curr-1] != 1 and key[curr-2] != 1) {
     	 curr = a[last_idx+1] + 1;
         continue;
     }
     else if(key[curr - 1] and key[curr - 2]) { 
     	curr = curr-2;
     	last_idx+=2;
     } 
     else if(!key[curr-1] and key[curr-2]) {
     	 curr--;
     } 
     else if(key[curr-1] and !key[curr-2]) {
        if(curr >= 2) ct++;
     	curr-=2;
     	last_idx++;
     }
  }
  cout << ct << endl;
   	}
  return 0;
} //good night.