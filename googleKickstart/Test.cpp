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
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++ << ": "; 
  ll n, m;
  cin >> n >> m;
  ll pt = -1;
  vll a(n);
  for(auto &x : a) cin >> x;
  for(ll i = 0; i < 10000000; i++) {
  	 ll tot = 0;
     for(auto j: a) {
     	tot+= (j^i);
     }
     if(tot <= m) {
     	pt = i;
     }

  }
  cout << pt << endl;
  }
  return 0;
} //good night.