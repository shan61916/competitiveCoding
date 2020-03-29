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

ll fast_exp(ll base, ll exp) {
  ll res=1;
  while(exp>0) {
    if(exp%2==1) res=(res*base)%mod;
      base=(base*base)%mod;
      exp/=2;
  }
  return res%mod;
}
ll modadd(ll x, ll y){return (x%mod + y%mod)%mod;}
ll modmul(ll x, ll y){return (x%mod * y%mod)%mod;}
ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
ll moddiv(ll x, ll y){return modmul(x, fast_exp(y, mod-2));}

vll fact(200100, 0); 
void ff() {
	fact[0] = 1;
	for(ll i = 1; i < 200100; i++){
		fact[i] = modmul(i, fact[i-1]);
	}
}

ll ncr(ll n, ll k)  
{  
    ll res = 1;  
    if ( k > n - k )  
        k = n - k;  
  
    for (ll i = 0; i < k; ++i)  
    {  
        res = modmul(res, n-i); 
        res = moddiv(res, i + 1);
    }  
    return res;  
}  

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ff();
  ll n, a, b;
  cin >> n >> a >> b;
  ll init = fast_exp(2, n);
  init = modsub(init, 1ll);
  ll ans = modsub(init, ncr(n, a));
  ans = modsub(ans, ncr(n, b));
  cout << ans << endl;
  return 0;
} //good night.