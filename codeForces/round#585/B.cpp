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
  vll a(n);
  for(ll i = 0; i < n; i++) {
  	ll tp;
  	cin >> tp;
  	if(tp < 0) a[i] = 1;
  	if(tp > 0) a[i] = 0;
  }
  ll ct = 0;
  ll ctt[2] = {1, 0};
  for(ll i = 0; i < n; i++) {
  	ct = (ct + a[i])%2;
  	ctt[ct]++;
  }
  ll neg = ctt[0]*ctt[1];
  ll pos = n*(n+1)/2;
  pos-=neg;
  cout << neg << " " << pos << endl;
  return 0;
} //good night.