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
  ll a1, a2 , k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  if(k1 > k2) {
  	swap(k1, k2);
  	swap(a1, a2);
  }
  ll p = n;
  ll mn = 0;
  ll tt = n/k1;
  ll off = min(tt, a1);
  n-= off*k1;
  mn+=off;
  tt = n/k2; 
  off = min(tt, a2);
  mn+=off;
  ll mx = 0;
  tt = (k1-1)*a1 + (k2-1)*a2; 
  if(tt >= p) {
  	mx = 0;
  } else {
  	mx = p - tt;
  }
  cout << mx << " " << mn << endl;
  return 0;
} //good night.