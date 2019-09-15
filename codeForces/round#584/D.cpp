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
  ll a, b, c, d; 
  cin >> a >> b >> c >> d;
  ll x = a+b ;
  ll y = c-d;
  ll ct = 0;
  if(x < 0) ct++;
  if(y < 0) ct++;
  if(y == 0 or ct == 1) {
  	cout << -1;
  	cout << endl;
  	continue;
  }
   cout << x/y << endl;
  }
  return 0;
} //good night.