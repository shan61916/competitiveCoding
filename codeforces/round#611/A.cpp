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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);


int main(){
 IOS
// #ifdef SHAN
//     freopen("input.txt" , "r" , stdin);  
// #endif
  ll T;
  cin >> T;
  while(T--) {
  ll a, b;
  cin >> a >> b;
  ll ct = 0;
  while(a != 24) {
    ct++;
    b++;
    if(b == 60) {
      a++;
      b = 0;
    }
  }
  cout << ct << endl;
}
  return 0;
} //good night.