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
   queue<ll> q1, q2; 
   string p;
   cin >> p;
   for(ll i = 0; i < (ll)p.length(); i++) {
   	 ll xx = (ll)(p[i] -'0');
   	 if(xx%2) q2.push(xx);
   	 else q1.push(xx);
   }
   string ans = "";
   for(ll i = 0; i < (ll)p.length(); i++) {
   	 ll s1 = 11;
   	 ll s2 = 11;
   	 if(!q1.empty()) {
   	 	s1 = q1.front();
   	 } 
   	 if(!q2.empty()) {
   	 	s2 = q2.front();
   	 }
   	 if(s1 < s2) {
   	 	ans+= (char)(s1+'0');
   	 	q1.pop();
   	 } else {
   	 	ans+= (char)(s2 + '0');
   	 	q2.pop();
   	 }
   }

   cout << ans << endl;
  }
  return 0;
} //good night.