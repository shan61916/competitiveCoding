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
ll n;
vll a;
ll maxSubArraySum() 
{ 
    ll max_so_far = -inf, max_ending_here = 0; 
  
    for (ll i = 0; i < n-1; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--) {
   cin >> n;
   a.resize(n);
   ll s = 0;
   for(ll i = 0; i < n; i++) {cin >> a[i]; s+= a[i];}
   ll a1 = maxSubArraySum();
   reverse(all(a));
   a1 = max(a1, maxSubArraySum());
   if(a1 < s) {
   	cout << "YES";
   } else {
   	cout << "NO"; 
   }
   cout << endl;
  }
  return 0;
} //good night.