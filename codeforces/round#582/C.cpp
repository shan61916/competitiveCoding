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
    ll n, m;
    cin >> n >> m;
    vector<ll> rem(10, 0); 
    ll s = 0;
    for(ll i = 1; i <= 10; i++) {
    	rem[i-1] = (m*i)%10;
    	s+=rem[i-1];
    }
    ll x = n/m ;
    ll tt = x/10;
    ll ans = 0;
    ans+= tt*s;
    ll todo = x - (tt*10);
    for(ll i = 0; i < todo; i++) ans+= rem[i] ;
    cout << ans << endl;
  }
  return 0;
} //good night.