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
   ll a, b, c, d, k;
   cin >> a >> b >> c >> d >> k;
   ll f1 = (a + c - 1)/c;
   ll f2 = (b + d - 1)/d;
   if(f1 + f2 > k) {
   	cout << -1 << endl;
   } else {
   	cout << f1 << " " << f2 << endl;
   }
  }
  return 0;
} //good night.