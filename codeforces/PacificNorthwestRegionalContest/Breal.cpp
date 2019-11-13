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
unordered_map<ll, ll> mp1, mp2;
ll tot = 0;
const int MAX = (int)(1e2) ;
vector<bool> prime(MAX + 1, true);
vll pp;
vector<bool> visited(MAX+1, false);
void SieveOfEratosthenes() {  
  
    for (int p=2; p*p<=MAX; p++) 
    {  
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=MAX; i += p) 
                prime[i] = false; 
        } 
    }
    for(ll i = 2; i <= MAX; i++) {
      if(prime[i]) pp.pb(i);
    }
}
void pri() {
   for(auto i: pp) {
    ll x1 = 0, x2 = 0;
    for(ll j = i; j < MAX; j+= i) {
      if(!(mp1[j] or mp2[j])) continue;
      x1+= mp1[j];
      x2+= mp2[j]; 
      ll xx = i;
      while(xx%i == 0) xx/=i;
      mp1[xx]+= mp1[j];
      mp2[xx]+=mp2[j];
      mp1[j] = 0;
      mp2[j] =0;
      visited[j]= true;
    }
    // cout << i << " " << x1 << " " << x2 << endl;
    tot+= (x1 * x2);
  }
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  for(ll i = a; i <= b; i++) mp1[i]++;
  for(ll j = c; j <= d; j++)mp2[j]++;
  ll ans = (b-a + 1) * (d-c+1);
  SieveOfEratosthenes();
  pri();
  // cout << tot << endl;
  cout << ans - tot << endl;
  return 0;
} //good night.