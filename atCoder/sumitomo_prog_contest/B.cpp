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
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  dll xx = ((dll)(n)/(dll)(1.08));
  // cout << xx << endl;
  ll cn1 = (ll)((ceil)(xx)* (dll)(1.08));
  ll cn2 = (ll)((floor)(xx)* (dll)(1.08));
  // cout << cn1 << " " << cn2 << endl;
  if(cn1 != n and cn2 != n) {
    cout << ":(";
  } else if(cn1 == n){ 
    cout << (ceil)(xx) << endl;
  } else cout << (floor)(xx) << endl;
  return 0;
} //good night.