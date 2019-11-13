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
const dll pi = 3.14159;

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll a, b, c;
  cin >> a >> b >> c;
  dll givn = (dll)((dll)b - ((dll)(c)/((dll)(a)*(dll)(a)))) ;
  if(c < a*a) {
  	 givn = (dll)(b)*((dll)(a)*(dll)(a));
  } 
  givn = (dll)(givn) * (2.00);
  givn = (dll)(givn)/(dll)(a);
  dll ans = atan(givn);
  dll res = (ans * 180.00)/(dll)(pi);
  cout << fixed << setprecision(10) << res << endl;

  return 0;
} //good night.