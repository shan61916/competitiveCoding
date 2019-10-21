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
   ll k; string s;
   cin >> k >> s;
   ll n = s.length();
   vector<ll> pref(n+1); 
   pref[0] = 0;
   unordered_map<ll, ll> key;
   for(ll i = 1; i <= n; i++) {
   	pref[i] += pref[i-1] + (s[i-1] == '1');
   	key[pref[i]]++;
   }
   ll ans = 0;
   for(ll i = 1; i <= n; i++) {
   	// cout << pref[i] + k << endl;
   	ans+= key[pref[i] + k] - 1;
   	key[pref[i]]--;
   }
   cout << ans << endl;

  return 0;
} //good night.