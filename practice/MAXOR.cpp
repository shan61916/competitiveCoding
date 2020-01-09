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
const ll mxn = (ll)(1e5 + 1);
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

const ll p = 257;             // base for the hash. (alpha)
ll pow_p[mxn];
void prep() {
  pow_p[0] = 1;               // pre-calculated powers of the base.
  for(ll i = 1; i < mxn; i++) {
    pow_p[i] = modmul(pow_p[i-1], p);
  }
}

ll addlast(ll currhash, ll val) {
  currhash = modmul(currhash, p);
  currhash = modadd(currhash,val);
  return currhash;
}
ll removelast(ll currhash, ll val){
  currhash = modsub(currhash, val);
  currhash = moddiv(currhash, p);
  return currhash;
}
ll addfirst(ll currhash, ll val, ll len) {
  // len is the current length, before adding.
  ll toadd = modmul(val, pow_p[len]);
  currhash = modadd(currhash, toadd);
  return currhash;
}
ll removefirst(ll currhash, ll val, ll len){
  ll torem = modmul(val, pow_p[len]);
  currhash = modsub(currhash, torem);
  return currhash;
}


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  
  return 0;
} //good night.