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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  ll xx = n/2;
  ll s1 = 0, s2 = 0;
  for(ll i = 0; i < n; i++) {
  	if(i < xx) s1+= a[i];
  	else s2+= a[i];
  }
  cout << (s1*s1) + (s2*s2) << endl;
  return 0;
} //good night.