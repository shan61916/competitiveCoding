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
const int MAX = (int)(1e6+1) ;
vector<bool> prime(MAX + 1, true);
vll pp;
void SieveOfEratosthenes() 
{  
  
    for (int p=2; p*p< MAX; p++) 
    {  
        if (prime[p] == true) 
        { 
            for (int i=p*p; i< MAX; i += p) 
                prime[i] = false; 
        } 
    }
    for(ll i = 2; i < MAX; i++) if(prime[i]) pp.pb(i);
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  ll ans = 0;
  SieveOfEratosthenes();
  while(n >= 4) {
    ans++;
    for(auto it: pp) {
       if(prime[n - it]) {
         n-= 2*it;
         break;
       }
    }
  }
  cout << ans << endl;
  return 0;
} //good night.