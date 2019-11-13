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
   ll n, k, d;
   cin >> n >> k >> d;
   set<ll> ss;
   vll arr(n);
   unordered_map<ll, ll> key;
   for(auto &x : arr) cin >>x;
   for(ll i = 0; i < d; i++) {
   	 ss.insert(arr[i]);
   	 key[arr[i]]++;
   }
   ll start = 0;
   ll mn = ss.size();
   for(ll i = d; i < n; i++) {
      if(key[arr[start]] == 1) {
      	ss.erase(ss.find(arr[start]));
      }
      key[arr[start]]--;
      key[arr[i]]++;
      ss.insert(arr[i]);
      mn = min(mn, (ll)ss.size());
      start++;
   }
   cout << mn << endl;
  }
  return 0;
} //good night.