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
bool can(ll x) {
  for(ll i = 2; i*i <= x; i++) {
    if(x%i == 0) return false;
  }
  return true;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  ll i = 2;
  while(1) {
    if(can(i) or can(i+n)) i++;
    else{
      cout << i+n << " " << i << endl;
      return 0;
    }
  }
  return 0;
} //good night.