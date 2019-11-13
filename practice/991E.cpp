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
ll n, k;
vector<ll> ct(10, 0);
ll todo;
ll uniq(ll x) {
	string xx = to_string(x);
	set<char> odo;
	for(auto it: xx) odo.insert(it);
	return odo.size();
}
ll recurse(ll idx, ll first, vector<ll> ctt, ll digit) {
   if(idx == k) {
   	 if(uniq(digit) == todo) {
   	 	cout << digit << endl;
   	 	return 1;
   	 }
   }
   ll ans = 0;
   ll start = 0;
   if(first == 0) start = 1;
   for(ll i = start; i <= 9; i++) {
   	  if(ctt[i] > 0) {
   	  	 ans+= recurse(idx+1, digit, ctt, digit);
   	  	 ctt[i]--;
   	  	 ans+= recurse(idx+1, digit , ctt, digit);
         ans+= recurse(idx+1, 1, ctt, (digit*10 + i));
   	  }
   }
   return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  todo = uniq(n);
  ct.assign(10, 0);
  string xx = to_string(n);
  k = (ll)xx.length();
  for(auto it: xx) ct[it-'0']++;
  cout << recurse(0, 0, ct, 0);
  return 0;
} //good night.