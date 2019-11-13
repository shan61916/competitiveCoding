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
  ll n, d, e;
  cin >> n >> d >> e;
  ll a2 = 5*e; 
  ll mn = INT_MAX, tt, zz, pp;
  for(ll i = 0; i <= (ll)(1e8); i++) {
     pp = d*i;
     if(pp > n) {
     	break;
     }
     tt = n - pp;
     zz = tt%a2;
     mn = min(mn, zz);
     if(mn == 0){
     	cout << 0;
     	return 0;
     }
  }
  cout << mn << endl;
  return 0;
} //good night.