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
ll mod = (ll)(1e9 + 7);
const ll N = 250100;
ll modadd(ll x, ll y){return (x%mod + y%mod)%mod;}
ll modmul(ll x, ll y){return (x%mod * y%mod)%mod;}
ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
// ll moddiv(ll x, ll y){return modmul(x, fast_exp(y, mod-2));}

vll fact(N, 0);
void f() {
  fact[0] = 1;
  for(ll i = 1; i < N; i++) {
    fact[i] = modmul(i, fact[i-1]);
  }
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n >> mod;
  ll ans = 0;
  f();
  for(ll i = 1; i <= n; i++) {
    ll a1 = fact[i];
    ll a2 = fact[n-i+1];
    ans = modadd(ans, modmul(n - i + 1, modmul(a1, a2)));
  }
  cout << ans << endl;
  return 0;
} //good night.